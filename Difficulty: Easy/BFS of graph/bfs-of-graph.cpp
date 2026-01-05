class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size(); 
        vector<int> ans(n+1,0); 
        vector<int> vbfs;
        
        ans[0]=1 ; 
        queue<int> q; 
        q.push(0); 
        while( !q.empty()){
            auto node = q.front();
            q.pop(); 
            vbfs.push_back(node); 
            
            for( auto &it : adj[node]){
                if( ans[it] == 0 ) {
                    ans [it] = 1; 
                    q.push(it); 
                }
            }
        }
       return vbfs; 
    }
};