class Solution {
public:

    class comp{
        public:
        bool operator()(const tuple<int,int,int>& a , const tuple<int,int,int>& b ){
            auto [ maxDiff , i , j] =a ;
            auto[ maxDiff1 , i1 , j1] =b; 

            return maxDiff > maxDiff1 ;
        }
    }; 

    vector<pair<int,int>>move= {{1,0},{0,-1},{0,1},{-1,0}}; 

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>> , comp> pq;
        int n = heights.size() , m = heights[0].size();
        vector<vector<int>>ans(n,vector<int>(m,INT_MIN));
        vector<vector<int>>vis(n,vector<int>(m,-1));
        pq.push({0,0,0}); 
        while(!pq.empty()){
            int size = pq.size(); 
            auto [ maxDiff , i , j ] = pq.top(); pq.pop();
            vis[i][j] = 1; 
            if( i == n-1 and j == m-1 ){
                return maxDiff; 
            }

            for(auto& it : move ){
                auto [row , col ] = it; 
                if( i+row<n and i+row>=0 and j+col<m and j+col>=0 and vis[i+row][j+col]  == -1){
                    int diff = abs(heights[i][j] - heights[i+row][j+col]); 
                    
                        ans[row+i][col+j] = max(diff , maxDiff);
                        pq.push({ ans[row+i][col+j] , row+i , col+ j}); 
                    
                } 
            }

        }

        return 0; 

    }
};