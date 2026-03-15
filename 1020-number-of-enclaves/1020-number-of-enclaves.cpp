class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        queue<pair<int,int>>q;
        for(int i = 0 ; i< m ;i++ ){
            if( grid[0][i] == 1 ){
                q.push({ 0,i});
            }
        }
        for(int i = 0 ; i<n ; i++ ){
            if( grid[i][0] == 1 ){
                q.push({i,0}); 
            }
        }
        for( int i = 0 ; i<n ; i++ ){
            if( grid[i][m-1] ==1 ){
                q.push({i, m-1}); 
            }
        }
        for( int i  = 0 ; i<m ; i++ ){
            if( grid[n-1][i] == 1  ){
                q.push({n-1, i});
            }
        }

        while(!q.empty()){
            auto [ row , col ] = q.front() ; q.pop(); 
            grid[row][col] =0; 
            int d1[] = {1 , -1 , 0 , 0};
            int d2[] = {0 , 0 , 1 , -1};

            for(int i = 0  ;i < 4 ; i++ ){
                if( row+d1[i]<n and row+d1[i]>=0 and col+d2[i]<m and col+d2[i]>=0 and grid[row+d1[i]][col+d2[i]] == 1 ){
                    q.push({ row+d1[i] , col+d2[i]}); 
                    grid[row+d1[i]][col+d2[i]] = 0 ; 
                }
            }


        }
        int count = 0;
        for(auto& it : grid){
            for( int i = 0 ; i< m ;i++ ){
                if( it[i] == 1 ) count++; 
            }
        }
        return count; 
    }
};