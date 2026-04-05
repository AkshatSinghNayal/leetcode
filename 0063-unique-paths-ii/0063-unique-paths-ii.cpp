class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid , vector<vector<int>>&dp , int i , int j  ){
        // base 
        if( i< 0 or j < 0 or obstacleGrid[i][j] == 1 ) return 0 ; 
        if( i == 0 and j == 0  ) return 1; 

        if(dp[i][j] != -1 ) return dp[i][j]; 
        int left = solve(obstacleGrid , dp , i-1 , j ); 
        int up = solve(obstacleGrid , dp , i , j-1 ); 

        return dp[i][j] = left+up; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 ) return 0; 
        vector<vector<int>>dp(n,vector<int>(m , -1)); 
        return solve(obstacleGrid , dp , n-1 , m-1  ); 
        
        
    }
};