class Solution {
public:

    int solve(vector<int>& nums, vector<int>&dp , int i ){
        // base
        if( i< 0 ) return 0;
        if(dp[i]!= -1 ) return dp[i]; 

        return dp[i] = max( nums[i]+solve( nums , dp , i-2 ) , solve(nums , dp , i-1)); 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,dp,n-1); 
    }
};