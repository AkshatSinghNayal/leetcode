class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev( amount + 1, 0);
        for (int i = 0; i <= amount; i++) {
            prev[i]= (i % coins[0] == 0) ? i/coins[0] : 1e9;
        }
        for (int i = 1; i <= n; i++) {
            vector<int>curr( amount + 1, 0);
            for (int j = 0; j <= amount; j++) {
                long long take = 1e9;
                if (j >= coins[i - 1]) {
                    take = 1 + curr[j - coins[i - 1]];
                }

                long long notTake = prev[j];

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }
        return (prev[amount] == 1e9 ) ? -1 : prev[amount];
    }
};