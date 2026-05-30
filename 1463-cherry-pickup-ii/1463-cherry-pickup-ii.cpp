class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(m + 1, vector<int>(m + 1, 0))
        );

        for (int row = n - 1; row >= 0; row--) {

            for (int c1 = 1; c1 <= m; c1++) {

                for (int c2 = 1; c2 <= m; c2++) {

                    int maxi = 0;

                    for (int d1 = -1; d1 <= 1; d1++) {

                        for (int d2 = -1; d2 <= 1; d2++) {

                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;

                            if (nc1 < 1 || nc1 > m ||
                                nc2 < 1 || nc2 > m)
                                continue;

                            int cherries =
                                (c1 == c2)
                                    ? grid[row][c1 - 1]
                                    : grid[row][c1 - 1] +
                                      grid[row][c2 - 1];

                            maxi = max(
                                maxi,
                                cherries + dp[row + 1][nc1][nc2]
                            );
                        }
                    }

                    dp[row][c1][c2] = maxi;
                }
            }
        }

        return dp[0][1][m];
    }
};