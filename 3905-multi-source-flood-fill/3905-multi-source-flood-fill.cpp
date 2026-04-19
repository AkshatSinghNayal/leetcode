class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        priority_queue<tuple<int,int,int>>pq; 
        vector<vector<int>> canvas(n , vector<int>(m , 0)); 
        
        for(auto& it : sources ){
            pq.push({ it[2] ,it[0], it[1]}); 
            canvas[it[0]][it[1]] = it[2]; 
        }
        vector<vector<int>>direction = {{1,0},{-1,0},{0,1},{0,-1}}; 

        while(!pq.empty()){
            vector<tuple<int,int,int>> temp; 
            int size = pq.size(); 
            while( size-- ){
                    auto [maxi , row , col ] = pq.top() ; pq.pop();
                for(auto& it : direction ){
                    int move1 = row+it[0] , move2 = col+it[1]; 
                    if( move1>=0 and move1 <n and move2 >= 0 and move2<m and canvas[move1][move2]  == 0  ){
                        temp.push_back({maxi , move1 , move2 });
                        canvas[move1][move2] = maxi; 
                    }
                }
            }
            for(auto& it : temp){
                pq.push(it); 
            }
        }
        return canvas; 
    }
};