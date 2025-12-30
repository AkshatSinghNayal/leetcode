class Solution {
public:

    int solve(vector<vector<int>>& grid , vector<vector<vector<int>>>& dp , int row , int rCol1 , int rCol2 , int rows  , int cols){

        if( rCol1 <0 or rCol1>=cols or rCol2<0 or rCol2>= cols) return -1e8; 
        if( row == rows-1 ){
            return( rCol1 == rCol2 ) ? grid[row][rCol1] : grid[row][rCol1]+grid[row][rCol2]; 
        }

        if( dp[row][rCol1][rCol2]  != -1 ) return dp[row][rCol1][rCol2]; 

        int maxi = INT_MIN;     
        for( int i  = -1 ; i<=1 ; i++){
            for( int j = -1 ; j<=1 ; j++){
                int val = (rCol1==rCol2) ? grid[row][rCol1] : grid[row][rCol1]+grid[row][rCol2]; 
                maxi=max(maxi , val+solve(grid , dp , row+1 , rCol1+i , rCol2+j , rows ,cols)); 
            } 
            
        }

        return dp[row][rCol1][rCol2] = maxi; 

    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(); 
        int cols = grid[0].size(); 
        vector<vector<vector<int>>>dp(rows ,vector<vector<int>>(cols , vector<int>( cols , -1 ))); 
        return solve( grid , dp , 0 , 0 , cols-1 , rows , cols) ;
    }
};