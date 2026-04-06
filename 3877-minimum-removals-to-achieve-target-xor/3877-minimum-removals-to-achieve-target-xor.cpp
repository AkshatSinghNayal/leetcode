class Solution {
public:

    int solve( vector<int>& nums , vector<vector<int>>& dp , int target  , int i ){
        // base here
        if (i < 0) {
    return target == 0 ? 0 : INT_MAX;
}
        if( dp[i][target]!= -1 ) return dp[i][target];

        int take = solve( nums , dp ,target^nums[i] , i-1);
int notTake = solve(nums, dp, target, i-1);
if (notTake != INT_MAX) notTake += 1;
        return dp[i][target] = min( take  , notTake );

    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int MAX_VAL = 1<<14 ;
        vector<vector<int>>dp(n , vector<int>( MAX_VAL , -1 )); 

        int ans = solve( nums ,dp , target , n-1 ) ;
        return ans == INT_MAX ? -1 : ans;

    }
};