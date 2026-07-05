class Solution {
public:

    int solve( int n , int m ,vector<vector<int>>&dp ){
        //base
        if( n == 0 and m == 0  ) return 1; 
        if(dp[n][m] != -1 ) return dp[n][m]; 

        int up = ( n-1 >=0 ) ? solve( n-1 , m , dp) : 0 ; 
        int left = ( m-1>= 0 ) ? solve(n , m-1  , dp) : 0;

        return dp[n][m] = (up+left);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m ,-1));
        return solve( n-1 , m-1 , dp ); 
    }
};