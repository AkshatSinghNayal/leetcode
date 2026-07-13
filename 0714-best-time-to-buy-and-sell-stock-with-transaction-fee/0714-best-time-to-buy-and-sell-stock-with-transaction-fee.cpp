class Solution {
public:

    int solve(vector<int>& prices, vector<vector<int>>& dp, int buy, int day, int fee) {
        if (day >= prices.size())
            return 0;

        if (dp[day][buy] != -1)
            return dp[day][buy];

        int profit = 0;

        if (buy) {
            int bought = solve(prices, dp, 0, day + 1, fee) - prices[day];
            int notBought = solve(prices, dp, 1, day + 1, fee);

            profit = max(bought, notBought);
        }
        else {
            int sell = solve(prices, dp, 1, day + 1, fee) + prices[day] - fee;
            int notSell = solve(prices, dp, 0, day + 1, fee);

            profit = max(sell, notSell);
        }

        return dp[day][buy] = profit;
    }


    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, dp, 1, 0, fee);
    }
};