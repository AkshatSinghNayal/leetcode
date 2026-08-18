class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size(); 
        for(int i  = 0 ;i<=n-k ;i++ ){
            unordered_set<int>st;
            for(int j = 0 ;j < k ; j++ ){
                int index = j+i; 
                if(!st.count(nums[index])){
                    mp[nums[index]]++; 
                    st.insert(nums[index]);
                }
            }
        }
        int maxi = INT_MIN; 
        for(auto& [ ele , freq] : mp ){
            if( freq == 1 ){
                maxi = max(maxi , ele );
            }
        }
        return maxi == INT_MIN ? -1 : maxi ;
    }
};