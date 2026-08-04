class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        vector<int> minCost(n, INT_MAX);

        priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, -1});

        int ans = 0;

        while (!pq.empty()) {
            auto [dist, node, par] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node]=true;
            ans+=dist;
            parent[node] = par ; 

            for(int next = 0 ; next<n ; next++ ){
                if(!visited[next]){
                int distance = abs(points[node][0] - points[next][0]) + abs(points[node][1] - points[next][1]); 
                    pq.push({ distance , next , node }); 
                    minCost[next] = min(minCost[next] , dist ); 
                }
            }
           
        }

        return ans;
    }
};