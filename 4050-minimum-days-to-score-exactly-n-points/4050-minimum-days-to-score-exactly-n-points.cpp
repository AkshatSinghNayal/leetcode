class Solution {
public:

    int solve(int n, vector<int>& dp) {

        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = 1e9;

        for (int i = 1; ; i++) {

            // points earned in i continuous earning days
            int sum = i * (i + 1) / 2;

            if (sum > n)
                break;

            // exact score reached
            if (sum == n) {
                ans = min(ans, i);
            }
            else {
                // i earning days
                // + 1 skip day
                // + solve remaining score
                ans = min(
                    ans,
                    i + 1 + solve(n - sum, dp)
                );
            }
        }

        return dp[n] = ans;
    }

    int minDays(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};