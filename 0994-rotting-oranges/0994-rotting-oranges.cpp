class Solution {
public:

    vector<vector<int>> dir ={{1,0} ,{0,-1} , {0,1} , {-1,0 }}; 

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q; 
        int count =0 ;  
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        for(int j =0; j<n ; j++ ){
            for(int i =0; i<m ; i++ ){
                if(grid[j][i] == 2 ){
                    q.push({j,i}); 
                    grid[j][i]=-1 ;
                }
                if(grid[j][i] == 1 ){
                    count++;
                }
            }
        }
        int steps = 0;
        while(!q.empty() and count > 0 ){
            int size = q.size(); 
            steps++; 
            for(int i  = 0;i < size ; i++ ){
            auto [ row , col  ] = q.front(); q.pop(); 
                    for(auto& it : dir ){
                int nr = row+it[0]; 
                int nc = col+it[1]; 

                if( nr < n and nc < m and nr>=0 and nc>=0 and grid[nr][nc] == 1 ){
                    q.push({nr , nc}); 
                    grid[nr][nc] = -1 ; 
                    count--; 
                }
            } 
            }
        }

        return (count == 0 ) ? steps :  -1 ; 

    }
};