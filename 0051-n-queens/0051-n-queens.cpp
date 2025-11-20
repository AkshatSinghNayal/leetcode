class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queen(n, -1); // queen[i] = column of the queen placed in row i
        backtrack(result, queen, 0, n);
        return result;
    }

private:
    // Backtracking function
    void backtrack(vector<vector<string>>& result, vector<int>& queen, int row, int n) {
        // If we have placed all queens, add the solution
        if (row == n) {
            result.push_back(generateBoard(queen, n));
            return;
        }

        for (int col = 0; col < n; ++col) {
            bool isSafe = true;
            
            // Check if the queen at (row, col) conflicts with previous queens
            for (int prevRow = 0; prevRow < row; ++prevRow) {
                int prevCol = queen[prevRow];

                // Check column conflict or diagonal conflict
                if (prevCol == col || abs(row - prevRow) == abs(col - prevCol)) {
                    isSafe = false;
                    break;
                }
            }

            if (isSafe) {
                queen[row] = col; // Place the queen
                backtrack(result, queen, row + 1, n); // Recurse to the next row
                queen[row] = -1; // Backtrack
            }
        }
    }

    // Generate the board from the queen array
    vector<string> generateBoard(const vector<int>& queen, int n) {
        vector<string> board(n, string(n, '.'));
        for (int row = 0; row < n; ++row) {
            board[row][queen[row]] = 'Q';
        }
        return board;
    }
};
