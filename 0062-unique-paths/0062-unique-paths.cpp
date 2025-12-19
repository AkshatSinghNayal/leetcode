class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0); // dp[j] stores number of ways to reach column j in current row

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0); // temporary array for the current row
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1; // start cell
                    continue;
                }

                int up = (i > 0) ? dp[j] : 0;       // value from previous row
                int left = (j > 0) ? temp[j-1] : 0; // value from left in current row

                temp[j] = up + left; // total ways to reach current cell
            }
            dp = temp; // update dp for the next row
        }

        return dp[n-1]; // bottom-right cell
    }
};
