class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq; 
        int n = heights.size() ; 
        int m = heights[0].size();
        vector<vector<int>> ans(n ,vector<int>(m , INT_MAX)); 
        pq.push({0 , {0 , 0 }}); 
        // ans[0][0] = 0 ; 

        int d1[4] = {-1 , 0 , 0, 1 }; 
        int d2[4] = {0 , -1 , 1 , 0}; 

        while(!pq.empty()){
            auto [dis  , index ] = pq.top() ; 
            auto [ row , col] = index ;  
            pq.pop() ; 
            if( row == n-1 and col == m-1 ) return dis ;      
            for( int i  = 0 ; i<4 ; i++ ){
                int movei =row+d1[i]; 
                int movej =col+d2[i]; 
                if (dis > ans[row][col]) continue;
                if( movei>= 0 and movei< n and movej>=0 and movej<m ){
                    
                    int distance = max(dis,abs(heights[movei][movej] - heights[row][col])
);
                    if(ans[movei][movej]>distance){
                        ans[movei][movej] = distance ; 
                        pq.push({distance,{movei ,movej}}); 
                    }


                }
            }
        }
        return -1; 
    }
};