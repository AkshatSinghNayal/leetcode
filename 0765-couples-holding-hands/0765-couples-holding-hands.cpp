class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v)
            parent[v] = u;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;

        DSU dsu(n);

        int components = n;

        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i] / 2;
            int b = row[i + 1] / 2;

            if (dsu.find(a) != dsu.find(b)) {
                dsu.unite(a, b);
                components--;
            }
        }

        return n - components;
    }
};
