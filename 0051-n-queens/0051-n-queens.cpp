class Solution {
public:

    bool check(int row, int col, vector<string>& board, int n) {

    // check same column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // check upper-right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}


    void helperFunction( int row , int n , vector<string>& board , vector<vector<string>>& ans){
        
        if( row == n ){
            ans.push_back(board); 
        }

        for( int col = 0 ; col <n ; col++ ){
            if( check( row , col , board , n )){
                board[row][col] = 'Q'; 
                helperFunction( row+1 , n , board , ans ); 
                board[row][col] = '.'; 

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n , string(n  , '.')); 
        vector<vector<string>> ans ; 
        helperFunction( 0 , n , board , ans ); 
        return ans ; 
    }
};