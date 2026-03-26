class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int MAX_VAL = 1 << 14;
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(MAX_VAL, INF));

        // Base case
        dp[0][nums[0]] = min(dp[0][nums[0]], 0);
        dp[0][0] = min(dp[0][0], 1);

        for (int i = 1; i < n; i++) {
            for (int x = 0; x < MAX_VAL; x++) {
                // Remove
                dp[i][x] = min(dp[i][x], 1 + dp[i-1][x]);

                // Keep
                int prev = x ^ nums[i];
                dp[i][x] = min(dp[i][x], dp[i-1][prev]);
            }
        }

        int ans = dp[n-1][target];
        return (ans >= INF) ? -1 : ans;
    }
};