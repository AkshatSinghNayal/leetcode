class Solution {
public:

    

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0]; 
        
        
        for(int i  = 1; i< n ; i++ ){
            int take = ( i - 2 >=0 ) ? nums[i]+dp[i-2] : nums[i]; 
            dp[i] = max(take,dp[i-1]); 
        }
        
        return dp[n-1]; 
    }
};