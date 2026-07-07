class Solution {
    int n;
    int memo[50][50][50];

    int dfs(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;

        // Out of bounds or thorn
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return -1e9;
        }

        // Reached destination
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if (memo[r1][c1][r2] != -1)
            return memo[r1][c1][r2];

        int cherries = grid[r1][c1] + (r1 == r2 ? 0 : grid[r2][c2]);

        int max_next = -1e9;

        for (int d1 = 0; d1 <= 1; d1++) {
            for (int d2 = 0; d2 <= 1; d2++) {
                max_next = max(max_next, dfs(r1 + d1, c1 + (1 - d1), r2 + d2, grid));
            }
        }
        return memo[r1][c1][r2] = cherries + max_next;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(memo, -1, sizeof(memo));
        return max(0, dfs(0, 0, 0, grid));
    }
};