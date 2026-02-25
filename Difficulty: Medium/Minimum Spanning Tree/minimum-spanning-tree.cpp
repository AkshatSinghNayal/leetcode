class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ; // weight node 
        vector<vector<pair<int,int>>>list(V);
        vector<int>vis(V , 0);
        int ans = 0 ; 

        for( auto& it :edges){
            list[it[0]].push_back({it[1] , it[2]}); 
            list[it[1]].push_back({it[0] , it[2]}); 
        }
        
        // weight node 
        
        pq.push({0 , 0});
        
        while(!pq.empty()){
            auto [ weight  , node] = pq.top(); 
            pq.pop() ; 
            if( vis[node]==1) continue;
            vis[node] = 1;
            
            
            ans+=weight ; 
            for(auto& it : list[node]){
                auto [ node1 , wt ] = it ; 
                pq.push({ wt , node1}); 
            }
        }
        
        
        return ans; 
        
        
    }
};