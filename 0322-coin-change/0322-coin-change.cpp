class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0) ? i/coins[0] : 1e9;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                long long take = 1e9;
                if (j >= coins[i - 1]) {
                    take = 1 + dp[i][j - coins[i - 1]];
                }

                long long notTake = dp[i - 1][j];

                dp[i][j] = min(take, notTake);
            }
        }
        return (dp[n][amount] == 1e9 ) ? -1 : dp[n][amount];
    }
};