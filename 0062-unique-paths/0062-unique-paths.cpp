class Solution {
public:

    // int solve(vector<vector<int>>& dp , int i , int j ){
    //     //base
    //     if( i<0 or j<0 ) return 0;
    //     if( i == 0 and j == 0  ) return 1; 

    //     if( dp[i][j] != -1 ) return dp[i][j]; 
    //     int left = solve( dp , i-1 , j);
    //     int right = solve( dp , i , j-1 );

    //     return dp[i][j] = left+right; 
    // }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m ,vector<int>(n,0)); 
        for(int i = 0 ; i< m ; i++ ) dp[i][0] = 1; 
        for(int i = 0 ; i< n ; i++ ) dp[0][i] = 1; 

        for( int i =1 ; i< m ; i++ ){
            for(int j = 1; j< n ; j++ ){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]; 
            }
        }
        return dp[m-1][n-1]; 
    }
};