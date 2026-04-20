class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>list(n);
        int i = 0 ; 
        for(auto& it : edges){
            list[it[0]].push_back({it[1] , succProb[i]}); 
            list[it[1]].push_back({it[0], succProb[i]});
            i++; 
        }
        vector<double>ans(n,DBL_MIN);
        ans[start] = 1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start}); 
        while(!pq.empty()){
            auto [ maxi , node ] = pq.top(); pq.pop(); 
            for(auto& it : list[node]){
                auto [ node2 , prob ]= it; 
                if(ans[node2] < prob*maxi ){
                    ans[node2] = prob*maxi;
                    pq.push({ans[node2] , node2}); 
                }
            }

        }
        return ans[end] ; 
    }
};