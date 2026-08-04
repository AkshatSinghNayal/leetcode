class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        vector<int> minCost(n, 0);

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, -1});

        int ans = 0;

        while (!pq.empty()) {
            auto [dist, node, par] = pq.top();
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = true;
            ans += dist;

            minCost[node] = dist;
            parent[node] = par;

            // Instead of adjacency list, check all other points
            for (int next = 0; next < n; next++) {
                
                    int distance = abs(points[node][0] - points[next][0]) +abs(points[node][1] - points[next][1]);

                    pq.push({distance, next, node});
                
            }
        }

        return ans;
    }
};