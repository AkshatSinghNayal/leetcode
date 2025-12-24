class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
              int row, int colIndexOfR1, int colIndexOfR2, int rowAtEachLayer,
              int colAtEachLayer) {

        if (colIndexOfR1 < 0 || colIndexOfR1 >= colAtEachLayer ||
            colIndexOfR2 < 0 || colIndexOfR2 >= colAtEachLayer)
            return -1e8;

        if (row == rowAtEachLayer - 1) {

            if (colIndexOfR1 == colIndexOfR2)
                return grid[row][colIndexOfR1];
            else
                return grid[row][colIndexOfR1] + grid[row][colIndexOfR2];
        }

        if (dp[row][colIndexOfR1][colIndexOfR2] != -1)
            return dp[row][colIndexOfR1][colIndexOfR2];

        int maxi = -1e8;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int value = 0;
                if (colIndexOfR1 == colIndexOfR2)
                    value = grid[row][colIndexOfR1];
                else
                    value = grid[row][colIndexOfR1] + grid[row][colIndexOfR2];

                int result = value + solve(grid, dp, row + 1, colIndexOfR1 + i,
                                           colIndexOfR2 + j, rowAtEachLayer,
                                           colAtEachLayer);
                maxi = max(maxi, result);
            }
        }

        return dp[row][colIndexOfR1][colIndexOfR2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rowAtEachLayer = grid.size();
        int colAtEachLayer = grid[0].size();

        vector<vector<vector<int>>> dp(
            rowAtEachLayer,
            vector<vector<int>>(colAtEachLayer,
                                vector<int>(colAtEachLayer, -1)));

        int row = 0;
        int colIndexOfR1 = 0, colIndexOfR2 = colAtEachLayer - 1;

        return solve(grid, dp, row, colIndexOfR1, colIndexOfR2, rowAtEachLayer,
                     colAtEachLayer);
    }
};
