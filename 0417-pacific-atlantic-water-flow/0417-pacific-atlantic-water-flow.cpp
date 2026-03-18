    class Solution {
    public:

        vector<vector<int>> distance ={{1,0} , {-1,0} , {0,1 } , {0,-1}};

        void DFS(vector<vector<int>>& heights,vector<vector<bool>>& vis , int i ,int j ){
            vis[i][j] = true;

            for(auto& it :distance ){
                int row = i+it[0]; 
                int col = j+it[1];

                if( row>=0 and col>= 0 and row<heights.size() and col < heights[0].size()){
                    if( !vis[row][col] and heights[row][col]>=heights[i][j]){
                        DFS(heights , vis, row, col);
                    }
                }
            }

        }

        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            int n = heights.size() , m=heights[0].size();
            vector<vector<int>>ans;
            vector<vector<bool>>pacific(n , vector<bool>(m ,false));
            vector<vector<bool>>atlantic(n , vector<bool>(m, false));

            for(int i = 0 ; i< n ;i++ ){
                DFS(heights ,  pacific , i,0 );
                DFS(heights , atlantic , i , m-1 );
            }

            for(int i = 0  ;i< m ;i++ ){
                DFS(heights ,pacific  , 0 , i); 
                DFS(heights , atlantic , n-1 , i);
            }

            for(int i = 0;i< n  ;i++ ){
                for(int j=0  ; j< m ;j++ ){
                    if( pacific[i][j] and atlantic[i][j]) ans.push_back({i,j});
                }
            }

            return ans ;

        }
    };