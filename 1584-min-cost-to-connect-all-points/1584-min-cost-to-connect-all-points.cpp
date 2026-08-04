class Disjointset {
public:
    vector<int> size, parent;

    Disjointset(int V) {
        size.resize(V + 1, 1);
        parent.resize(V + 1);

        for (int i = 0; i <= V; i++)
            parent[i] = i;
    }

    int findParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize(int u, int v) {
        int NodeA = findParent(u);
        int NodeB = findParent(v);

        if (NodeA == NodeB)
            return;

        if (size[NodeA] > size[NodeB]) {
            parent[NodeB] = NodeA;
            size[NodeA] += size[NodeB];
        } else {
            parent[NodeA] = NodeB;
            size[NodeB] += size[NodeA];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

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

        Disjointset ds(n);

        int ans = 0;
        int cnt = 0;

        for (auto &[wt, u, v] : edges) {
            if (ds.findParent(u) != ds.findParent(v)) {
                ds.unionBySize(u, v);
                ans += wt;
                cnt++;

                if (cnt == n - 1)
                    break;
            }
        }

        return ans;
    }
};