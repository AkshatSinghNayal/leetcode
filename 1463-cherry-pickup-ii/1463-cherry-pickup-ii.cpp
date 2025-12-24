class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int colIndexOfR1, int colIndexOfR2, int rowAtEachLayer, int colAtEachLayer) {
        // Out of bounds check
        if (colIndexOfR1 < 0 || colIndexOfR1 >= colAtEachLayer || colIndexOfR2 < 0 || colIndexOfR2 >= colAtEachLayer)
            return -1e8; 

        // Base case: If we've reached the last row
        if (row == rowAtEachLayer - 1) {
            // If both players are at the same column, take the cherry once, else take both cherries
            if (colIndexOfR1 == colIndexOfR2)
                return grid[row][colIndexOfR1];
            else
                return grid[row][colIndexOfR1] + grid[row][colIndexOfR2];
        }

        // If already computed, return the value from dp table
        if (dp[row][colIndexOfR1][colIndexOfR2] != -1)
            return dp[row][colIndexOfR1][colIndexOfR2];

        int maxi = -1e8;

        // Try all combinations of moving both players by -1, 0, or +1 in their respective columns
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int value = 0;
                if (colIndexOfR1 == colIndexOfR2)
                    value = grid[row][colIndexOfR1];  // If both players are at the same column, take cherry once
                else
                    value = grid[row][colIndexOfR1] + grid[row][colIndexOfR2];  // Else, take both cherries

                // Recursively find the max value by exploring the next row with new column positions
                int result = value + solve(grid, dp, row + 1, colIndexOfR1 + i, colIndexOfR2 + j, rowAtEachLayer, colAtEachLayer);
                maxi = max(maxi, result);
            }
        }

        // Store the result in dp table
        return dp[row][colIndexOfR1][colIndexOfR2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rowAtEachLayer = grid.size(); 
        int colAtEachLayer = grid[0].size(); 

        // Initialize dp table to store the results of subproblems
        vector<vector<vector<int>>> dp(rowAtEachLayer, vector<vector<int>>(colAtEachLayer, vector<int>(colAtEachLayer, -1)));

        int row = 0;
        int colIndexOfR1 = 0, colIndexOfR2 = colAtEachLayer - 1;

        // Call the solve function with proper bounds
        return solve(grid, dp, row, colIndexOfR1, colIndexOfR2, rowAtEachLayer, colAtEachLayer);
    }
};
