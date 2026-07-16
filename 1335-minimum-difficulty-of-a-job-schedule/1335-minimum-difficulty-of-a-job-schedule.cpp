class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {

        int n = job.size();

        if (n < d) return -1;

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));

        // Base case: day = 1
        int mx = 0;
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, job[i]);
            dp[i][1] = mx;
        }

        // Fill DP
        for (int day = 2; day <= d; day++) {

            for (int idx = n - day; idx >= 0; idx--) {

                int maxi = 0;

                for (int i = idx; i <= n - day; i++) {

                    maxi = max(maxi, job[i]);

                    if (dp[i + 1][day - 1] != INT_MAX)
                        dp[idx][day] = min(dp[idx][day], maxi + dp[i + 1][day - 1]);
                }
            }
        }

        return dp[0][d];
    }
};