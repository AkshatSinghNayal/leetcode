class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indgree(V); 
        vector<vector<int>>list(V);
        for(auto& it : edges ){
            list[it[1]].push_back(it[0]); 
            indgree[it[0]]++; 
        }
        priority_queue<int>pq;
        for(int i =  0; i< V ;i++ ){
            if(indgree[i] == 0 ) pq.push(i);
        }
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            ans.push_back(node); 
            for(auto& it : list[node]){
                indgree[it]--; 
                if( indgree[it] == 0  ) pq.push(it); 
            }
        }
        return ans.size() == V ; 
    }
};