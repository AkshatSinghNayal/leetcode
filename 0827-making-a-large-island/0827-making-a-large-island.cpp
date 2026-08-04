class Disjointset {
public:
    vector<int> size, parent;

    Disjointset(int V) {
        size.resize(V, 1);
        parent.resize(V);

        for (int i = 0; i < V; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int helper(vector<vector<int>>& grid, int i, int j, int n, Disjointset &ds) {

        unordered_set<int> st;

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                grid[nr][nc] == 1) {

                st.insert(ds.findParent(nr * n + nc));
            }
        }

        int area = 1;

        for (auto parent : st)
            area += ds.size[parent];

        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        Disjointset ds(n * n);

        // Build DSU
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) continue;

                int node = i * n + j;

                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adj = nr * n + nc;
                        ds.unionBySize(node, adj);
                    }
                }
            }
        }

        int maxi = 0;

        // Try every 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    maxi = max(maxi, helper(grid, i, j, n, ds));
            }
        }

        // All 1's case
        for (int i = 0; i < n * n; i++) {
            if (ds.findParent(i) == i)
                maxi = max(maxi, ds.size[i]);
        }

        return maxi;
    }
};