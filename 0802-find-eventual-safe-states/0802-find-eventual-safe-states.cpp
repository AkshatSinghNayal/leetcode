class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>mp;
        int n =  graph.size();
        vector<int>ind(n);

        for(int i  = 0 ;i<n ;i++ ){
            for(auto& it : graph[i]){
                mp[it].push_back(i);
                ind[i]++;
            }
        }
        queue<int>q;
        vector<int>ans; 

        for(int i  = 0 ;i<n; i++ ){
            if(ind[i] == 0  ) q.push(i);
        }

        while(!q.empty()){
            auto node = q.front() ;q.pop(); 
            ans.push_back(node); 

            for(auto& it : mp[node]){
                ind[it]--; 
                if(ind[it] == 0 ) q.push(it); 
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};