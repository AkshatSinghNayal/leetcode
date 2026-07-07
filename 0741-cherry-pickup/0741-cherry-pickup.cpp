class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        const int NEG = -1e9;

        static int dp[50][50][50];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dp[i][j][k] = NEG;

        // Base 
        dp[n - 1][n - 1][n - 1] = grid[n - 1][n - 1];

        int nr[] = {1, 0};
        int nc[] = {0, 1};

        for (int r1 = n - 1; r1 >= 0; r1--) {
            for (int c1 = n - 1; c1 >= 0; c1--) {
                for (int r2 = n - 1; r2 >= 0; r2--) {

                    int c2 = r1 + c1 - r2;

                    if (c2 < 0 || c2 >= n) continue;

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    if (r1 == n - 1 && c1 == n - 1) continue; 

                    int currSum = grid[r1][c1] + ((r1 == r2 && c1 == c2) ? 0 : grid[r2][c2]);

                    int maxi = NEG;

                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 2; j++) {

                            int nr1 = r1 + nr[i];
                            int nc1 = c1 + nc[i];
                            int nr2 = r2 + nr[j];
                            int nc2 = nr1 + nc1 - nr2;

                            if (nr1 >= n || nc1 >= n || nr2 >= n || nc2 >= n) continue;

                            maxi = max(maxi, dp[nr1][nc1][nr2]);
                        }
                    }

                    dp[r1][c1][r2] = currSum + maxi;
                }
            }
        }

        return max(0, dp[0][0][0]);
    }
};