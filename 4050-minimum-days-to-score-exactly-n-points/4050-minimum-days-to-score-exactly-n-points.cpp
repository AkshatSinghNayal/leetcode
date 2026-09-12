class Solution {
public:

    int solve(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n < 0) return 1e9;

        if (dp[n] != -1)
            return dp[n];

        // notTake immediately
        int ans = 2 + solve(n - 1, dp);

        int eaten = 0;

        // take repeatedly:
        // eat 2, then 3, then 4, ...
        for (int streak = 1; ; streak++) {

            eaten += streak + 1;

            if (eaten > n)
                break;

            // We completely finish n using takes
            if (eaten == n) {
                ans = min(ans, streak);
                break;
            }

            // streak number of takes
            // then notTake => +2 cost and eat 1
            ans = min(
                ans,
                streak + 2 +
                solve(n - eaten - 1, dp)
            );
        }

        return dp[n] = ans;
    }

    int minDays(int n) {

        vector<int> dp(n + 1, -1);

        // Starting streak is 0:
        // first take eats 1 with cost 1.
        return 1 + solve(n - 1, dp);
    }
};