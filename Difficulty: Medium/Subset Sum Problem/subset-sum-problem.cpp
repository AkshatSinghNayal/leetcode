class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // Create the dp table: n rows (items), sum+1 columns (target sum)
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        // Initialize the first column (target sum 0 is always achievable)
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;  // Sum 0 is always achievable (take no elements)
        }
        
        // Initialize the first row (consider only arr[0])
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }

        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = dp[i-1][target];  // Do not include arr[i]
                bool take = false;
                
                if (arr[i] <= target) {
                    take = dp[i-1][target - arr[i]];  // Include arr[i]
                }

                dp[i][target] = take || notTake;  // Take or not take the element
            }
        }

        // The last cell of the dp table contains the answer
        return dp[n-1][sum];
    }
};
