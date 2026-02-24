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
        int result = 0 ;
        for(int i =  1; i<= V ; i++ ){
            result = max(result,ans[i]); 
        }
        return ( result == INT_MAX ) ? -1 : result   ; 

        
    }
};