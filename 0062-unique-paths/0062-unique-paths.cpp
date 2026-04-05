class Solution {
public:

    int solve(vector<vector<int>>& dp , int i , int j ){
        //base
        if( i<0 or j<0 ) return 0;
        if( i == 0 and j == 0  ) return 1; 

        if( dp[i][j] != -1 ) return dp[i][j]; 
        int left = solve( dp , i-1 , j);
        int right = solve( dp , i , j-1 );

        return dp[i][j] = left+right; 
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m ,vector<int>(n,-1)); 
        return solve(dp,m-1,n-1); 
    }
};