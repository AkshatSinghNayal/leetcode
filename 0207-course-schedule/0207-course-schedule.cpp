class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pre) {
        vector<vector<int>>list(V); 
        queue<int>q;
        vector<int>indegree(V);
        for(auto& it : pre){
            list[it[1]].push_back(it[0]); 
            indegree[it[0]]++; 
        }
        for(int i  = 0 ;i<indegree.size() ;i++ ){
            if(indegree[i] == 0  ) q.push(i);
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i  = 0;i<size; i++ ){
                auto edge = q.front(); q.pop(); 

                for(auto& it : list[edge]){
                    indegree[it]--; 
                    if(indegree[it] == 0  ) q.push(it);
                }
            }
        }
        for(auto& it : indegree ){
            if( it > 0 ) return false;
        }
        return true;
    }
};