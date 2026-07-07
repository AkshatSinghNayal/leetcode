class Solution {
    int n;
    int dp[50][50][50];

    int dfs(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int c2 = r1+c1 -r2; 
        int nr[] = {1,0}; 
        int nc[] = {0,1}; 
        
        if( r1 == n-1 and c1 == n-1 ) return grid[r1][c1];
        if(r1>=n or r2>=n or c1>=n or c2 >=n or grid[r1][c1] == -1 or grid[r2][c2] == -1 ) return -1e9; 

        if(dp[r1][c1][r2] !=-1 ) return dp[r1][c1][r2]; 

        int currSum =  grid[r1][c1] + ( r1 == r2 and c1 == c2 ? 0 : grid[r2][c2] ) ; 
        int maxi = -1e9; 

        for(int i  = 0;i<2 ;i++ ){
            for(int j = 0;j<2 ; j++ ){
                maxi = max(maxi , dfs( r1+nr[i] , c1+nc[i] , r2+nr[j] , grid)); 
            }
        }

        return dp[r1][c1][r2] = maxi+currSum; 

    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, dfs(0, 0, 0, grid));
    }
};