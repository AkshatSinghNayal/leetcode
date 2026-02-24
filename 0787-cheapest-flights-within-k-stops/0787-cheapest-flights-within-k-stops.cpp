class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>ans(n , INT_MAX ); 
        // step distance node ;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> q; 
        q.push({0 , {0 , src}}); 
        vector<vector<pair<int,int>>>list(n); 

        for(auto& it : flights){
            list[it[0]].push_back({it[1] , it[2]}); 
        }

        while(!q.empty()){
            auto [ steps , info ] = q.top() ; 
            auto [distance ,  node ] = info ; 
            q.pop(); 

            if( steps > k ) continue; 

            for(auto& it : list[node]){
                auto [ node1 , dist ] = it ; 
                if( ans[node1] > dist+distance ){
                    ans[node1] = dist+distance ; 
                    q.push({ steps+1 , { ans[node1] , node1}}); 
                }
            }


        }

        return ( ans[dst] == INT_MAX ) ? -1 : ans[dst]; 

    }
};