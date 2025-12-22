class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m  =  grid.size() ;
        int n = grid[0].size(); 
        vector<vector<long long>> dp(m , vector<long long>(n));
        dp[0][0] = grid[0][0]; 
        for( int i  = 1 ; i< n ; i++) dp[0][i] = dp[0][i-1]+ grid[0][i]; 
        for( int j = 1 ; j< m ; j++) dp[j][0] = dp[j-1][0] + grid[j][0]; 
        
        for( int i = 1 ; i<m ; i++){
            for( int j = 1 ; j<n ; j++){
                int current =  grid[i][j]; 
                dp[i][j] = min( current+dp[i-1][j] ,current+ dp[i][j-1]);
                
            }
        }
       
        long long ans = dp[m-1][n-1]; 
        return (int)ans; 
    }
};