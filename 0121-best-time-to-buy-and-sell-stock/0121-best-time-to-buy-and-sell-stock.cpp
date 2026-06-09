class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int cap, vector<vector<int>>& dp) {
        // Base case 1: If we run out of days or have completed our 1 transaction limit
        if (i == prices.size() || cap == 0) return 0;

        // Check if already computed
        // Since 'buy' is 0 or 1, and 'cap' is 0 or 1, we can map the state to a 2D DP table.
        // We can represent the state as dp[i][0] for 'can buy' and dp[i][1] for 'must sell'
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if (buy) {
            // Option 1: Buy today (reduces cash by prices[i], capacity stays same until we sell)
            int take = -prices[i] + solve(prices, i + 1, 0, cap, dp);

            // Option 2: Skip today
            int skip = solve(prices, i + 1, 1, cap, dp);

            profit = max(take, skip);
        } else {
            // Option 1: Sell today (increases cash by prices[i], reduces remaining transaction capacity to 0)
            int sell = prices[i] + solve(prices, i + 1, 1, cap - 1, dp);

            // Option 2: Skip today
            int skip = solve(prices, i + 1, 0, cap, dp);

            profit = max(sell, skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[n][2] stores:
        // dp[i][1] -> Max profit at day i if we are looking to BUY
        // dp[i][0] -> Max profit at day i if we are looking to SELL
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start at day 0, looking to buy (1), with a capacity of 1 transaction
        return solve(prices, 0, 1, 1, dp);
    }
};