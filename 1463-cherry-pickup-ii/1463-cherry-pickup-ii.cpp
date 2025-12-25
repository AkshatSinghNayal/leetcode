class Solution {
public:

    int solve(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp , int row , int colR1 , int colR2 , int n , int totalRow ){

        if( colR1<0 or colR1>=n or colR2<0 or colR2>=n ) return  -1e9; 

        if (row == totalRow-1) {
        return (colR1 == colR2) ?  grid[row][colR1] : grid[row][colR1] + grid[row][colR2];
        }

        if( dp[row][colR1][colR2] != -1 ) return dp[row][colR1][colR2] ; 

        int maxi = -1e9 ; 
        for( int i  = -1 ; i<= 1; i++){
            for(int j= - 1; j<= 1; j++){
                int value = ( colR1 ==colR2 ) ? grid[row][colR1] : grid[row][colR1] + grid[row][colR2]; 
                int result = value + solve( grid , dp , row+1 , colR1+i , colR2+j ,n  , totalRow) ;
                maxi = max( maxi ,result ) ; 
            }
        }

        return dp[row][colR1][colR2] = maxi ; 

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int layers = grid.size(); 
        int rowCount =  grid[0].size(); 
        int colCount = grid[0].size(); 
        
        vector<vector<vector<int>>>dp(layers , vector<vector<int>>(rowCount , vector<int>(colCount,-1))); 
        return solve( grid , dp , 0 , 0 , colCount-1 , colCount , layers ); 
    }
};