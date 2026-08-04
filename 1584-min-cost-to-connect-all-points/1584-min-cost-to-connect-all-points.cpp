class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (rank[u] < rank[v])
            swap(u, v);

        parent[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        vector<tuple<int, int, int>> edges;

        // Build all edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;
        int edgesUsed = 0;

        for (auto &[dist, u, v] : edges) {
            if (find(u) != find(v)) {
                unite(u, v);
                ans += dist;
                edgesUsed++;

                if (edgesUsed == n - 1)
                    break;
            }
        }

        return ans;
    }
};