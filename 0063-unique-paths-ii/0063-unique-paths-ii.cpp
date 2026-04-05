class Solution {
public:

    // int solve(vector<vector<int>>& obstacleGrid , vector<vector<int>>&dp , int i , int j  ){
    //     // base 
    //     if( i< 0 or j < 0 or obstacleGrid[i][j] == 1 ) return 0 ; 
    //     if( i == 0 and j == 0  ) return 1; 

    //     if(dp[i][j] != -1 ) return dp[i][j]; 
    //     int left = solve(obstacleGrid , dp , i-1 , j ); 
    //     int up = solve(obstacleGrid , dp , i , j-1 ); 

    //     return dp[i][j] = left+up; 
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 ) return 0; 
        vector<vector<int>>dp(n,vector<int>(m , 0)); 
        bool flag1 = false , flag2 = false;
        for(int i = 0 ; i< n ; i++ ){
           if(!flag1){
            dp[i][0] = (obstacleGrid[i][0] == 0 ) ? 1 : 0;
            if(dp[i][0] ==0 ) flag1 = true;
           }
           else{
            dp[i][0] = 0; 
           }
        }
        for(int i = 0 ; i< m ; i++ ){
            if(!flag2){
                dp[0][i] = (obstacleGrid[0][i] == 0 ) ? 1 : 0; 
                if(dp[0][i] == 0 ){
                    flag2 = true;
                }
            }
            else{
                dp[0][i] =0; 
            }
        }

        for(int i =  1; i< n ; i++ ){
            for(int j =  1 ; j< m ; j++ ){
                dp[i][j] = (obstacleGrid[i][j] == 0 ) ? dp[i-1][j]+dp[i][j-1] : 0; 
            }
        }
        return dp[n-1][m-1]; 
        
    }
};