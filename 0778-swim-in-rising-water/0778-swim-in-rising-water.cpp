class Solution {
public:

    class comp{
        public:
        bool operator()(const tuple<int,int,int>&a , const tuple<int,int,int>&b ){
            return get<0>(a) > get<0>(b); 
        }
    }; 

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,comp>pq;
        int n  = grid.size(); 
        vector<vector<int>>ans(n , vector<int>(n , INT_MAX));
        vector<vector<int>>dist{{1,0},{0,1},{0,-1},{-1,0}}; 
        pq.push({grid[0][0], 0 , 0 }); 
        ans[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [ maxi , i , j ] = pq.top(); pq.pop(); 
            if(ans[i][j] > maxi ) continue; 

            if( i == n-1 and j == n-1 ) return maxi; 

            for(auto& it : dist ){
                int move1 = i+it[0]; 
                int move2 = j+it[1]; 

                if(move1<n and move1>=0 and move2 < n and move2>= 0 ){
                    int temp = max(maxi ,grid[move1][move2]); 
                    if( ans[move1][move2] > temp ){
                        ans[move1][move2] = temp;
                        pq.push({ans[move1][move2] , move1 , move2}); 
                    }
                }

            }

        }
        return -1; 
         
    }
};