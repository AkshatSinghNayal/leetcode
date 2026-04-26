class Disjoint{
public: 
    vector<int> size, parent; 

    Disjoint(int V){
        size.resize(V, 1); 
        parent.resize(V); 
        for(int i = 0; i < V; i++) parent[i] = i; 
    }

    int findParent(int n){
        if(parent[n] == n) return n; 
        return parent[n] = findParent(parent[n]); 
    }

    bool unionBySize(int u, int v){
        int pu = findParent(u); 
        int pv = findParent(v); 

        if(pu == pv) return true; // cycle

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        Disjoint d(n * m);

        int dx[] = {0, 1};   // only right & down (IMPORTANT)
        int dy[] = {1, 0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int node = i * m + j;

                for(int k = 0; k < 2; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni < n && nj < m && grid[i][j] == grid[ni][nj]){
                        int neighbor = ni * m + nj;

                        if(d.unionBySize(node, neighbor))
                            return true; 
                    }
                }
            }
        }
        return false;
    }
};