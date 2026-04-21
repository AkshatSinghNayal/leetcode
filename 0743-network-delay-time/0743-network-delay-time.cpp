class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>ans(n+1 , INT_MAX ); 
        vector<vector<pair<int,int>>>list(n+1); 
        queue<pair<int,int>> q; // to time 
        q.push({ k , 0 }); 
        ans[k] = 0; 

        for(auto& it : times ){
            list[it[0]].push_back({it[1],it[2]}); 
        }

        while(!q.empty()){
            auto [ node , time ] = q.front(); 
            q.pop(); 

            if( ans[node] < time ) continue ;

            for(auto& it : list[node]){
                auto [ toNode , reachTime ] = it; 
                if( ans[toNode] > time+ reachTime ){
                    ans[toNode] = time+reachTime ; 
                    q.push({toNode , ans[toNode]}); 
                }
            }
        }
        int result  = *max_element(ans.begin()+1 , ans.end()); 
        return ( result == INT_MAX ) ? -1 : result; 

    }
};