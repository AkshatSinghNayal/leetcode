class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses; 
        unordered_map<int,vector<int>>mp; 
        vector<int>indegree(n); 
        queue<int>q; 
        int count = 0;

        for(int i  = 0 ;i<pre.size(); i++ ){
            int B = pre[i][1] , A = pre[i][0]; 
            mp[B].push_back(A);
            indegree[A]++; 
        }

        for(int i  = 0 ;i<indegree.size(); i++ ){
            if(indegree[i] == 0  ) q.push(i); 
        }

        while(!q.empty()){
            auto node = q.front(); q.pop(); 
            count++; 

            for(auto& it : mp[node]){
                indegree[it]--; 
                if( indegree[it] == 0  ) q.push(it);
            }
        }

        return count == n ; 
    }
};