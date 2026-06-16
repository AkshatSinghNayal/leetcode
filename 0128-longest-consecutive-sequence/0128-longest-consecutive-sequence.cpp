class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp ;
        int maxi = INT_MIN;
        for(auto& it : nums ){
            mp[it] = 1 ; 
        }
        for(auto& it : nums ){
            auto digit = it; 
            int count = 0 ; 
            if( mp.count( it-1)){
                while(mp.count(it-1)){
                    count+=mp[it-1]; 
                    mp.erase(it-1);
                    it--; 
                }
            }
            mp[digit]+=count; 
            maxi = max(maxi , mp[digit]); 
            
        }
        return maxi == INT_MIN ? 0 : maxi  ; 

    }
};

