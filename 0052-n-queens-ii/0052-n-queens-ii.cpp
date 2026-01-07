class Solution {
public:
    bool check(int row, int col, vector<vector<int>>& ans, int n) {
        // Check all previously placed queens (rows 0 to row-1)
        for(int i = 0; i <= row; i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == 1) {
                    // Same column check
                    if(j == col) return false;
                    
                    // Diagonal check using abs()
                    if(abs(i - row) == abs(j - col)) return false;
                }
            }
        }
        return true;
    }

    int helperFunction(int n, vector<vector<int>>& ans, int row, int count) {
        if(row == n) {
            return count + 1;
        }

        for(int col = 0; col < n; col++) {
            if(check(row, col, ans, n)) {
                ans[row][col] = 1; 
                count = helperFunction(n, ans, row + 1, count);
                ans[row][col] = 0; 
            }
        }
        return count; 
    }

    int totalNQueens(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0)); 
        return helperFunction(n, ans, 0, 0); 
    }
};