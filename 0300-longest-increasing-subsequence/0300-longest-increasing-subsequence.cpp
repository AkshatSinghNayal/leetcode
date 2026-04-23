class Solution {
public:

    int solve(vector<vector<int>>&dp , int  i , int prev ,int n , vector<int>& nums ){
        //base
        if( i == n ) return 0;
        if( dp[i][prev+1] != -1 ) return dp[i][prev+1]; 

        int take = 0; 
        if( prev == -1 or nums[prev]<nums[i]){
            take = 1+solve(dp , i+1, i , n , nums ); 
        }
        int notTake = solve(dp , i+1 , prev , n , nums ); 

        return dp[i][prev+1] = max(take , notTake ); 
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1)); 
        return solve( dp, 0 , -1 , n , nums); 
    }
};