class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<tuple<int,int,int>>q; 
        int n =  mat.size() , m = mat[0].size(); 
        vector<vector<int>>vis(n , vector<int>(m , -1)); 
        for(int i  = 0 ; i< n ; i++ ){
            for(int j = 0; j< m ;j++ ){
                
                if(mat[i][j] == 0  ){
                vis[i][j] =1; 
                q.push({ i , j , 0});

                } 
            }
        }

        vector<pair<int,int>>dist ={{1,0},{-1,0},{0,1},{0,-1}}; 
        while(!q.empty()){
            auto [ row ,col , dis] = q.front() ; q.pop(); 

            for(auto& it : dist ){
                auto [ newR , newC] = it; 
                int move1 = newR+row, move2 = newC+col ;

                if( move1>=0 and move1< n and move2>=0 and move2<m and vis[move1][move2] == -1 and mat[move1][move2] == 1 ) {
                    vis[move1][move2] =1;
                    mat[move1][move2] = dis+1; 
                    q.push({move1 , move2 , dis+1}); 
                }

            }
            
        }
        return mat ; 
    }
};