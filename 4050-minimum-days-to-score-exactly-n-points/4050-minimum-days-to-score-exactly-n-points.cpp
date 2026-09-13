class Solution {
public:

    int solve(int n, vector<int>& dp) {

        if (n == 0) return 0;
        if (n < 0) return 1e9;

        if (dp[n] != -1)
            return dp[n];

        // reset immediately
        int ans = 2 + solve(n - 1, dp);

        int eaten = 0;
        int nextEat = 2;
        int cost = 0;

        while (eaten + nextEat <= n) {

            eaten += nextEat;
            nextEat++;
            cost++;

            // only take operations
            if (eaten == n) {
                ans = min(ans, cost);
                break;
            }

            // after these takes, reset
            ans = min(
                ans,
                cost + 2 + solve(n - eaten - 1, dp)
            );
        }

        return dp[n] = ans;
    }

    int minDays(int n) {

        vector<int> dp(n + 1, -1);

        // first take from streak = 0:
        // eat 1, cost 1
        return 1 + solve(n - 1, dp);
    }
};