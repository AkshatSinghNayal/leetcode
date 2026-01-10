class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n - 1; i++) {
            if (grid[i][m - 1] != grid[i + 1][m - 1])
                return false;
        }

        for (int j = 0; j < m - 1; j++) {
            if (grid[n - 1][j] == grid[n - 1][j + 1])
                return false;
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (grid[j][i] != grid[j + 1][i] or
                    grid[j][i] == grid[j][i + 1])
                    return false;
            }
        }

        return true;
    }
};