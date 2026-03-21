class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>list( n ); 
        for(auto& it : flights ){
            list[it[0]].push_back({it[1] , it[2]}); 
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ; // node , dis 

        vector<int>ans(n , INT_MAX ); 
        queue<tuple<int,int,int>>q;
        q.push({src,0 ,0}); 

        while(!q.empty()){
            auto [ currNode , currDis , count ] = q.front(); q.pop(); 

            if( count>k  ) continue;

            for(auto& it : list[currNode]){
                auto [toNode , toDis] = it;

                if( ans[toNode] > toDis+currDis ){
                    ans[toNode] = toDis+currDis;
                    q.push({toNode , toDis+currDis , count+1}); 
                }

            }
        }


        return ( ans[dst] == INT_MAX ) ? -1 : ans[dst]; 


    }
};