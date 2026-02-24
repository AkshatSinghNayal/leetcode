class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int dst) {
        vector<int>ans(V+1 ,INT_MAX); 
        // time node 
        priority_queue< pair<int,int> ,  vector<pair<int,int>> , greater<pair<int,int>>> pq ; 
        pq.push({ 0  , dst }); 
        ans[dst] = 0 ;  
        vector<vector<pair<int,int>>> list(V+1); 
        for(auto& it : times ){
            list[it[0]].push_back({it[1] , it[2]}); 
        }

        while(!pq.empty()){
            auto [ time , node  ] = pq.top() ; 
            pq.pop() ; 

            if( ans[node] < time ) continue; 

            for(auto& it : list[node]){
                auto [node1 , t ] = it; 
                
                if( ans[node1] > time+t ){
                    ans[node1] = time+t ; 
                    pq.push({ans[node1], node1} ); 
                }
            }
        }
        int result = *max_element(ans.begin()+1 , ans.end()); 
        return ( result == INT_MAX ) ? -1 : result   ; 

        
    }
};