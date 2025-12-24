class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for( int i = 0  ; i< n ; i++) dp[0][i] = matrix[0][i]; 
        for( int i =  1 ; i < n ; i++){
            int left = 1e9; 
            int right = 1e9; 
            for( int j  = 0  ; j< n ; j++){
                int up = dp[i-1][j]; 
                if( j-1 >= 0  )  left =  dp[i-1][j-1]; 
                if( j+1 <n )  right =  dp[i-1][j+1]; 

                dp[i][j] = matrix[i][j] + min({ up , left , right }); 
            }
        }
        int mini = INT_MAX  ; 
        for( int i  = 0 ; i< n  ; i++){
            int val = dp[n-1][i] ; 
            mini = min( mini , val ) ; 
        }
        return mini ; 
    }
};