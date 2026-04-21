class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        // attach smaller tree under larger one
        if (size[a] < size[b]) swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<tuple<int,int,int>> cells;

        // store (height, i, j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        DSU dsu(n * n);
        vector<vector<bool>> active(n, vector<bool>(n, false));

        vector<pair<int,int>> dir{{1,0},{0,1},{0,-1},{-1,0}};

        for (auto &[h, i, j] : cells) {
            active[i][j] = true;

            int id1 = i * n + j;

            for (auto &d : dir) {
                int ni = i + d.first;
                int nj = j + d.second;

                if (ni >= 0 && nj >= 0 && ni < n && nj < n && active[ni][nj]) {
                    int id2 = ni * n + nj;
                    dsu.unite(id1, id2);
                }
            }

            // check connectivity
            if (dsu.find(0) == dsu.find(n*n - 1)) {
                return h;
            }
        }

        return -1;
    }
};