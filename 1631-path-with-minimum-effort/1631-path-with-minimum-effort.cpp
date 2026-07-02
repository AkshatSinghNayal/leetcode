class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dir = {{0,-1},{0,1},{1,0},{-1,0}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        ans[0][0] = 0; 
        pq.push({0,0,0}); 
        while(!pq.empty()){

            auto [ dist , row ,col ] = pq.top() ; pq.pop(); 

            for(auto& it : dir ){
                int nr = row+it[0]; 
                int nc = col+it[1]; 


                if( nr<n and nr>=0 and nc<m and nc>=0 ){
                    int newDist = max(dist, abs(heights[row][col] - heights[nr][nc])); 
                    if(ans[nr][nc] > newDist){
                        ans[nr][nc] = newDist; 
                        pq.push({ans[nr][nc],nr,nc}); 
                    }
                }


            }
        }
        for(auto& it : ans){
            for(int i  = 0;i<m ; i++ ){
                cout << it[i] << " " ; 
            }
            cout<<endl; 
        }
        return ans[n-1][m-1]; 

    }
    
};