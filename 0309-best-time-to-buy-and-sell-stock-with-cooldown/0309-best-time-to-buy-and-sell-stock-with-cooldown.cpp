class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[i][1] = max profit starting from day i when we can buy
        // dp[i][0] = max profit starting from day i when we have a stock to sell
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // Can buy
            dp[i][1] = max(
                -prices[i] + dp[i + 1][0],
                dp[i + 1][1]
            );

            // Have stock, can sell
            dp[i][0] = max(
                prices[i] + dp[i + 2][1],   // cooldown
                dp[i + 1][0]
            );
        }

        return dp[0][1];
    }
};