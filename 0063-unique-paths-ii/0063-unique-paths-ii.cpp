class Solution {
public:

    // int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int i , int j ){
    //     //base

    //     if( i == 0 and j == 0 ) return 1; 

    //     if(dp[i][j] != -1 ) return dp[i][j]; 

    //     long long up =   ( i-1>=0 and grid[i-1][j] != 1 ) ? solve(grid , dp , i-1 , j) : 0; 
    //     long long left = ( j-1 >=0 and grid[i][j-1] != 1 ) ? solve(grid,dp, i , j-1 ) : 0;

    //     return dp[i][j] =(left+up); 
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n  = grid.size() , m = grid[0].size(); 
        if(grid[0][0] == 1 or grid[n-1][m-1] ==1 ) return 0; 
        vector<vector<int>>dp(n,vector<int>(m ,1));

        for(int i  = 0;i<m ; i++ ){
            if(grid[0][i] == 1 ){
                while(i<m){
                    dp[0][i] = 0;
                    i++; 
                }
            }
        }
        for(int i = 0; i< n; i++ ){
            if(grid[i][0] ==  1 ){
                while(i<n ){
                    dp[i][0] = 0; 
                    i++;
                }
            }
        }

        for(int i  =1 ; i< n; i++ ){
            for(int j =1 ;j<m ; j++ ){
                if(grid[i][j] == 1 or i == 0 and j == 0) continue;
                long long up =   ( i-1>=0 and grid[i-1][j] != 1 ) ? dp[i-1][j]: 0; 
                long long left = ( j-1 >=0 and grid[i][j-1] != 1 ) ? dp[i][j-1]: 0;

                dp[i][j] = up+left;

            }
        }

        for(auto& it : dp ){
            for(int i = 0;i<m ;i++ ){
                cout<<it[i] << "  "; 
            }
            cout<<endl;
        }

        return dp[n-1][m-1];

    }
};