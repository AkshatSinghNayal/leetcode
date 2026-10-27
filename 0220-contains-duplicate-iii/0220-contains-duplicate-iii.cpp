class Solution {
public:

    bool find( int idx , int target , set<int>& st ){
        auto it = st.lower_bound( idx-target );
        return it!=st.end() and *it <= target+idx;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int,int>>temp; 
        int left =0 , right =0 , n = nums.size();
        for(int i = 0;i<n; i++ ){
            temp.push_back({nums[i],i}); // contains the ele ->index relation
        }

        sort(temp.begin(),temp.end()); 

        set<int>st;

        while(right<n){

            // so i do have to find the valid range of the valueDiff then do Bs on that 

            while( left < right and abs(temp[left].first - temp[right].first) > valueDiff ){
                st.erase(temp[left].second);
                left++; 
            }

            if(find( temp[right].second , indexDiff , st)) return true;
            st.insert(temp[right].second); 

            right++; 
        }
        return false;
    }
};