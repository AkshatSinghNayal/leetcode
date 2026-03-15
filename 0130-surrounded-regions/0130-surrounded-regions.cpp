class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<vector<char>> temp( n , vector<char>(m , 'X'));

        queue<pair<int,int>>q;
        for(int i = 0 ; i< m ;i++ ){
            if( grid[0][i] == 'O' ){
                q.push({ 0,i});
            }
        }
        for(int i = 0 ; i<n ; i++ ){
            if( grid[i][0] == 'O' ){
                q.push({i,0}); 
            }
        }
        for( int i = 0 ; i<n ; i++ ){
            if( grid[i][m-1] =='O' ){
                q.push({i, m-1}); 
            }
        }
        for( int i  = 0 ; i<m ; i++ ){
            if( grid[n-1][i] =='O'  ){
                q.push({n-1, i});
            }
        }

         while(!q.empty()){
            auto [ row , col ] = q.front() ; q.pop(); 
            temp[row][col] ='O';
            grid[row][col] ='X'; 
            int d1[] = {1 , -1 , 0 , 0};
            int d2[] = {0 , 0 , 1 , -1};

            for(int i = 0  ;i < 4 ; i++ ){
                if( row+d1[i]<n and row+d1[i]>=0 and col+d2[i]<m and col+d2[i]>=0 and grid[row+d1[i]][col+d2[i]] == 'O' ){
                    q.push({ row+d1[i] , col+d2[i]});     
                }
            }


         }    

        grid=temp;
    }
};