class Solution {
public:

    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>&dp , int ro , int col1, int col2 , int col, int row  ){
        // base 
        if( ro>= row or col1 >= col or col2 >= col or col1<0 or col2<0 ) return -1e5; 

        if( ro == row-1 ){
            int val = ( col1 == col2 ) ? grid[ro][col1] : grid[ro][col1]+grid[ro][col2] ;
            return val; 
        }

        if( dp[ro][col1][col2] != -1 ) return dp[ro][col1][col2] ; 
        
        int maxi  = 0; 
        for( int i = -1 ;i<= 1 ; i++ ){
            int result =0; 
            for(int j = -1 ; j<= 1 ; j++ ){
                int value = ( ro < row and col1 == col2 ) ? grid[ro][col1] : grid[ro][col1]+grid[ro][col2] ;
                result = value+ solve(grid , dp , ro+1, col1 + i , col2+j , col , row);
                maxi = max( result , maxi ) ;    
            }
            
        }
        return dp[ro][col1][col2] = maxi  ;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size(); 
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m , -1))); 
        return solve( grid , dp, 0 ,0, m-1 , m, n ) ; 
    }
};