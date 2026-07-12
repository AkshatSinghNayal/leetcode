class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans; 
        queue<pair<int,vector<int>>>q; 
        vector<vector<int>>list(n);

        for(int i = 0;i<graph.size(); i++ ){
            for(int j = 0; j<graph[i].size(); j++ ){
                list[i].push_back(graph[i][j]); 
            }
        }

        q.push({0,{0}});
        while(!q.empty()){
            auto [ node , vec ] = q.front(); q.pop(); 

            if(node == n-1 ) ans.push_back(vec); 

            for(auto& it : list[node]){
                vector<int>temp = vec; 
                temp.push_back(it); 
                q.push({it , temp}); 
            }
        }

        return ans; 
    }
};