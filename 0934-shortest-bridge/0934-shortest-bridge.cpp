class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>>q; // row , col , dis
        int n = grid.size(); 
        for(int i = 0 ; i< n ; i++ ){
            for(int j = 0 ; j< n ; j++ ){
                if(grid[i][j] ==1 ){
                    q.push({i,j,0}); 
                    grid[i][j] = -1; 
                    break;
                }
            }
            if(q.size() >= 1 ) break;
        }

        int d1[] = {1,-1,0,0};
        int d2[]= {0,0, 1, -1}; 
        while(true){
    int size = q.size();
    bool added = false;

    for(int j = 0; j < size; j++){
        auto [row , col , dis] = q.front();
        q.pop();

        for(int i = 0 ; i<4 ; i++ ){
            int move1 = d1[i] , move2 = d2[i];

            if(row+move1<n && row+move1>=0 && col+move2<n && col+move2>=0 && grid[row+move1][col+move2]==1){
                grid[row+move1][col+move2] = -1;
                q.push({row+move1 , col+move2 , 0});
                added = true;
            }
        }

        q.push({row,col,0});
    }

    if(!added) break;
}
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0 ; i< size; i++ ){
                auto [ ro , co , dist ] = q.front(); 
                q.pop(); 
                for(int i = 0 ; i<4 ; i++ ){
                int move1 = d1[i] , move2 = d2[i];
                if( ro+move1<n and ro+move1>=0 and co+move2 <n and co+move2>=0 ){
                    
                if( grid[ro+move1][co+move2] == 1  ) return dist; 
                if(grid[ro+move1][co+move2] == 0){
                    q.push({ro+move1 , co+move2 , dist+1});
                    grid[ro+move1][co+move2] = -1; 
                }
                
            }
        }

            }
        }
        return -1; 
    }
};