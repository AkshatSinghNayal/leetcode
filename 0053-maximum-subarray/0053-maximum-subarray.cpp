class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e5  , best = -1e5;  
        for(auto& it : nums){
            best = max( best+it , it );
            ans = max( ans , best ); 
        }

        return ans; 
    }
};