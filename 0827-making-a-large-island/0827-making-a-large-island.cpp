class DistjointSet{
    public:
    vector<int> size , parent;
    DistjointSet( int V ){
        size.resize(V+1 , 1); 
        parent.resize(V+1); 

        for(int i = 0 ; i<=V; i++ ){
            parent[i] = i;
        }
    }

    int findParent( int n ){
        if( parent[n] == n ) return n ;
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize( int u , int v ){
        int pu = findParent(u); 
        int pv = findParent(v);

        if( pu == pv ) return ;

        if( size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu]+=size[pv]; 
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu]; 
        }
    }
};

class Solution {
public:

    vector<vector<int>>dist = {{0,-1},{0,1},{1,0},{-1,0}};
    int helper(vector<vector<int>>& grid, int i, int j, int n, DistjointSet& d) {
        unordered_set<int> components;

        // Check all 4 neighbors of the current 0 cell
        for(auto& it : dist) {
            int nr = it[0] + i; 
            int nc = it[1] + j;

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                int adjNode = nr * n + nc;
                components.insert(d.findParent(adjNode)); // Insert ultimate parent to avoid duplicates
            }
        }

        int totalSize = 1; // 1 for the current '0' being flipped to '1'
        for(auto& parentNode : components) {
            totalSize += d.size[parentNode]; // Add the size of each unique neighboring island
        }

        return totalSize;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DistjointSet d(n*n);
        bool hasZero = false;


        for(int i =  0; i< n; i++ ){
            for(int j = 0  ;j < n; j++ ){
                if( grid[i][j] == 0  ){
                    hasZero = true;
                    continue;
                }
                int node1 = i*n+j;

                for(auto& it : dist ){
                    int nr = it[0]+i; 
                    int nc = it[1]+j;

                    if( nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc] == 1 ){
                        int node2 = nr*n+nc;
                        d.unionBySize(node1 , node2 );
                    }
                }

            }
        }

        if(!hasZero) return n*n; 

        int maxi = INT_MIN;
        for(int i = 0 ;i<n ;i++ ){
            for(int j = 0; j<n ;j++ ){
                if(grid[i][j] == 1 ) continue; 

                int newMax = helper( grid , i , j , n ,d ); 
                maxi = max(maxi , newMax );
            }
        }
        return maxi; 
    }
};