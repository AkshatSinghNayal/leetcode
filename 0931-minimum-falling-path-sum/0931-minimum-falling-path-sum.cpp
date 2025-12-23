class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row,
              int col, int n) {
        // Out of bounds check - must come BEFORE accessing matrix
        if (col < 0 || col >= n)
            return INT_MAX;
        
        // Base case: If we've reached the first row, return the matrix value
        if (row == 0)
            return matrix[row][col];

        // If already computed, return the stored result
        if (dp[row][col] != INT_MIN)
            return dp[row][col];

        // Calculate the minimum falling path sum from three possible directions
        int up = solve(matrix, dp, row - 1, col, n);
        int left = solve(matrix, dp, row - 1, col - 1, n);
        int right = solve(matrix, dp, row - 1, col + 1, n);

        // Handle overflow: only add if the path is valid
        int minPath = min({up, left, right});
        if (minPath == INT_MAX)
            dp[row][col] = INT_MAX;
        else
            dp[row][col] = matrix[row][col] + minPath;

        return dp[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        // Try all starting positions in the last row
        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, solve(matrix, dp, n - 1, col, n));
        }

        return result;
    }
};