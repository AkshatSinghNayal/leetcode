class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>ans;
        vector<int>indgree(V); 
        vector<vector<int>>list(V);
        for(auto& it : edges ){
            list[it[0]].push_back(it[1]); 
            indgree[it[1]]++; 
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
        return ans ; 
        
    }
};