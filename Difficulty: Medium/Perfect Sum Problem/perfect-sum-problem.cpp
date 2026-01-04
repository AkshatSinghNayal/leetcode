class Solution {
  public:
    
    int solve(vector<int>& arr, vector<vector<int>>& dp, int target, int i) {
        
        if (i < 0) return (target == 0);

        if( dp[i][target] != -1 ) return dp[i][target]; 
        
        int notTake = solve(arr, dp, target, i - 1);
        int take = 0;
        
        if (arr[i] <= target) {
            take = solve(arr, dp, target - arr[i], i - 1);
        }
        
        return dp[i][target] = (take + notTake);
    }
        
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(arr, dp, target, n - 1);
    }
};
