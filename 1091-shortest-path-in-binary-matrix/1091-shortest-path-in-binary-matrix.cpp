class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n  =  grid.size(); 
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1 ) return -1; 
        vector<vector<int>>vis(n,vector<int>(n ,-1)); 
        vis[0][0] =1; 
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>>pq;
        pq.push({1,0,0}); 
        int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

        while(!pq.empty()){
            auto [ cost , row , col  ] = pq.top(); pq.pop(); 
            if( row == n-1 and col == n-1 ) return cost; 

            for(int i  = 0;i<8 ; i++ ){
                int nr = row+dr[i]; 
                int nc = col+dc[i]; 

                if( nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc] != 1 and vis[nr][nc] == -1){
                    pq.push({cost+1 , nr , nc }); 
                    vis[nr][nc] = 1; 
                }
            }
        }
        return -1; 
    }
};