class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[index][buy] represents the maximum profit achievable from `index` day onwards.
        // `buy = 0` means we are allowed to buy (or have not bought yet).
        // `buy = 1` means we have bought a stock and must sell it before buying again.
        // We need `n+1` rows to handle the base case `index == n`.
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Iterate from the last day backwards to the first day.
        // This is because our recurrence relations depend on `index + 1`.
        for (int index = n - 1; index >= 0; index--) {
            // Iterate for both possible 'buy' states (0 and 1).
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                // Case 1: We are allowed to buy (buy == 0)
                if (buy == 0) {
                    // Option A: Buy the stock today.
                    // Profit: -price[index] + max profit from next day, now with stock (buy=1).
                    // Option B: Don't buy the stock today.
                    // Profit: max profit from next day, still without stock (buy=0).
                    profit = max(-prices[index] + dp[index + 1][1], dp[index + 1][0]);
                }
                // Case 2: We have already bought a stock (buy == 1)
                else {
                    // Option A: Sell the stock today.
                    // Profit: price[index] + max profit from next day, now without stock (buy=0).
                    // Option B: Don't sell the stock today.
                    // Profit: max profit from next day, still with stock (buy=1).
                    profit = max(prices[index] + dp[index + 1][0], dp[index + 1][1]);
                }
                dp[index][buy] = profit;
            }
        }

        // The final answer is the maximum profit starting from day 0,
        // when we are allowed to buy (buy = 0).
        return dp[0][0];
    }
};