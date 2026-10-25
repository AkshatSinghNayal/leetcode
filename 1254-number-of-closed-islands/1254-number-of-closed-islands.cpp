class Solution {
public:
    
    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}} ; 

    void visit(queue<pair<int,int>>& q , vector<vector<int>>& grid, int n , int m ){
        while(!q.empty()){
            auto [ row , col ] = q.front() ; 
            q.pop(); 
            grid[row][col] = 1; 

            for(auto& it : dir ){
                int nr = row+it.first; 
                int nc = col+it.second;

                if( nr < 0 or nr >=n or nc<0 or nc>=m or grid[nr][nc] == 1 ) continue;
                q.push({nr,nc}); 

            }

        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        queue<pair<int,int>>q; 
        for(int i  =0 ;i<m ;i++ ){
            int ele = grid[0][i]; 
            if(ele == 0) q.push({0,i}); 
        }
        for(int i = 0 ;i<m; i++ ){
            int ele = grid[n-1][i]; 
            if(ele == 0) q.push({n-1,i}); 
        }
        for(int i = 0; i<n; i++ ){
            int ele = grid[i][0]; 
            if( ele == 0) q.push({i,0}) ; 
        }
        for(int i = 0; i<n; i++ ){
            int ele = grid[i][m-1]; 
            if( ele == 0) q.push({i,m-1}) ; 
        }

        visit(q,grid,n,m); 
        
        int count = 0; 
        for(int i= 1; i<n; i++){
            for(int j =1; j<m; j++ ){
                int ele = grid[i][j]; 
                if( ele == 0 ){
                    q.push({i,j}); 
                    count++;
                }
                visit(q,grid,n,m); 
                
            }
        }

        return count;

    }
};