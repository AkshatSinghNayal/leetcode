class Solution {
public:

    long long solve(vector<vector<int>>& grid , vector<vector<long long>>& dp ,int m , int n ){
        if( m == 0 and n  == 0 ) return grid[m][n] ; 
        if( m<0 or n <0 ) return INT_MAX ; 

        if( dp[m][n] != -1 ) return dp[m][n]; 

        long long up = grid[m][n]+solve( grid , dp , m-1 , n ) ; 
        long long left = grid[m][n]+solve( grid , dp , m ,  n-1 ) ; 

        return dp[m][n] = min( up , left ); 

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m  =  grid.size() ;
        int n = grid[0].size(); 
        vector<vector<long long>> dp(m , vector<long long>(n,-1));
        long long result =   solve( grid , dp , m-1 , n-1 ) ; 
        return (int)result;
    }
};