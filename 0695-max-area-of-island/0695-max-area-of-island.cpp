class DSU{
    public:
    vector<int>parent,size;

    DSU( int v ){
        parent.resize(v+1); 
        size.resize(v+1,1);

        for(int i  = 0 ; i<=v ;i++ ){
            parent[i] = i ;
        }
    }
    int find( int u ){
        if( parent[u] == u ) return u ; 
        return parent[u] = find(parent[u]); 
    }

    void unite( int u , int v ){
        int pu = find(u); 
        int pv = find(v); 

        if( pu == pv ) return ;

        if( size[pu] >= size[pv]){
            size[pu]+=size[pv]; 
            parent[pv] = pu; 
        }
        else{
            size[pv]+=size[pu]; 
            parent[pu] = pv;
        }
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        DSU d(n*m); 
        int maxi = 0 ;

        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,-1},{0,1}}; 

                bool found = false;
        for( int i  = 0 ;i<n; i++ ){
            for(int j  = 0 ; j<m ; j++ ){
                int node = i*m+j;
                if( grid[i][j] == 0 ) continue;
                if( grid[i][j] == 1) found = true;
                for(auto& [row , col] : dir ){
                    int nr = i+row , nc = j+col; 

                    if( nr <0 or nc <0 or nr>=n or nc>=m ) continue;
                    if( grid[nr][nc] == 1){
                        d.unite(node,nr*m+nc);
                    }
                }

                maxi = max( maxi , d.size[d.find(node)]);
            }
        }
        
        return (!found) ? 0 :maxi;
    }
};