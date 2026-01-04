class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size(); 
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = 1;
        if (arr[0] <= target)
            dp[0][arr[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= target; tar++) {
                dp[i][tar] = dp[i-1][tar];  // not take

                if (arr[i] <= tar) {
                    dp[i][tar] += dp[i-1][tar - arr[i]]; // take
                }
            }
        }

        return dp[n-1][target];
    }
};
