class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        queue<pair<int,int>> q;  
        int oneCount = 0;

        for( int i  =  0 ; i< n; i++ ){
            for( int j  = 0 ; j<m ; j++ ){
                if( grid[i][j] == 2){
                    q.push({i,j}); 
                }
                if( grid[i][j] ==  1){
                    oneCount++; 
                }
            }
        }

        if( oneCount == 0 ) return 0 ; 
        int count =0 ;
        vector<vector<int>> vis( n ,vector<int>(m ,0)); 

        while(!q.empty()){
            count++; 
            int size = q.size()  ;
            
            for(int i  = 0 ;i < size ; i++ ){

                auto [first , second] = q.front() ; 
                 q.pop() ; 

                // case up 1
            if( first-1>=0 and grid[first-1][second] ==  1 and vis[first-1][second] == 0){
                vis[first-1][second] =1 ; 
                oneCount--; 
                q.push({first-1, second}); 
            }
            // case down 2
            if( first+1<n and grid[first+1][second] ==  1 and vis[first+1][second] == 0){
                vis[first+1][second] =1 ; 
                oneCount--; 
                q.push({first+1, second}); 
            }
            // case left 3

            if( second-1>=0 and grid[first][second-1] ==1 and vis[first][second-1] == 0  ){
                vis[first][second-1] =1 ; 
                oneCount--; 
                q.push({first , second-1}); 
            }
            // case right 4
            if( second+1<m and grid[first][second+1] ==1 and vis[first][second+1] == 0  ){
                vis[first][second+1] =1 ; 
                oneCount--; 
                q.push({first , second+1}); 
            }
            }
        }
        return ( oneCount == 0 ) ? count-1 : -1;
    }
};