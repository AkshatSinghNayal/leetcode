class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<long long> rowSum(n, 0), colSum(m, 0);
        long long total = 0;

        // Precompute row and column sums
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        if(total % 2) return false;

        long long half = total / 2, curr = 0;

        // Check row-wise partition
        for(int i = 0; i < n; i++) {
            curr += rowSum[i];
            if(curr == half) return true;
        }

        curr = 0;

        // Check column-wise partition
        for(int j = 0; j < m; j++) {
            curr += colSum[j];
            if(curr == half) return true;
        }

        return false;
    }
};