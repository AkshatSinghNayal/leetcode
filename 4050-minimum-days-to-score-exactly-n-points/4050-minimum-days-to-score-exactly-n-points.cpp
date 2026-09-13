class Solution {
public:
    int minDays(int n) {

        int limit = 1e5;

        int sm = 0;
        int var = 1;

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        while (sm <= limit) {

            sm += var;

            for (int i = 1; i <= n; i++) {

                if (i - sm >= 0) {
                    dp[i] = min(
                        dp[i],
                        dp[i - sm] + var + 1
                    );
                }
            }

            var++;
        }

        return dp[n] - 1;
    }
};