class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n);

        // Calculate bonus for each item
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (items[j][0] % items[i][0] == 0) bonus[i]++;
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            // First copy with bonus (0-1 knapsack)
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + 1 + bonus[i]);
            }

            // Additional copies without bonus (unbounded knapsack)
            for (int b = price; b <= budget; b++) {
                dp[b] = max(dp[b], dp[b - price] + 1);
            }
        }

        return dp[budget];
    }
};