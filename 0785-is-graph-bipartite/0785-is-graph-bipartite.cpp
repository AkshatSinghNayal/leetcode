class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> color(n,-1);
        queue<int> q; 
        for(int i = 0 ; i< n ;i++ ){
            if( color[i] == -1 ){
                q.push(i); 
                color[i] = 0;

                while(!q.empty()){
                    auto node = q.front();
                    q.pop() ; 
                    for(auto& it : graph[node]){
                        if( color[it] == -1 ){
                            color[it] = 1 -color[node];
                            q.push(it);
                        }
                        else{
                            if(color[node] == color[it]){
                                return false; 
                            }
                        }
                    }
                }


            }
        }

        return true; 
    }
};