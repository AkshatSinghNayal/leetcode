class Solution {
  public:
    
   bool solve( vector<int>& arr , vector<vector<int>>& dp , int i , int target ){
        
        if (target == 0) return true;  // Base case: If target is 0, we found a subset
        if (i < 0) return false;  // Base case: If index goes out of bounds, no subset sum possible
        
        if (dp[i][target] != -1) return dp[i][target];  // Check if result is already computed
        
        // Recursively check both cases: include or exclude the current element
        bool take = false;
        if (arr[i] <= target) {
            take = solve(arr, dp, i - 1, target - arr[i]);  // Include the current element
        }
        bool notTake = solve(arr, dp, i - 1, target);  // Exclude the current element
        
        // Memoize the result for the current subproblem
        return dp[i][target] = take || notTake;  // If either case works, return true
    }
        
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size(); 
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));  // dp[i][target] initialized to -1
        return solve(arr, dp, n - 1, sum);  // Start from the last index and the target sum
    }
};
