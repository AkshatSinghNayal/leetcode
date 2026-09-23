class DSU{
    public:
    vector<int>parent,size;

    DSU(int V ){
        parent.resize(V+1); size.resize(V+1,1); 

        for(int i = 0 ;i<=V; i++ ){
            parent[i] = i; 
        }
    }

    int find(int u ){
        if( u == parent[u] ) return u ; 
        return parent[u] = find(parent[u]); 
    }

    void unite( int u , int v ){
        int a = find(u); 
        int b  =  find(v); 

        if( a ==b ) return ; 

        if(size[a] > size[b]){
            size[a]+=size[b]; 
            parent[b] = a; 
        }
        else{
            size[b]+=size[a]; 
            parent[a] = b ; 
        }
    }

    bool connected( int u , int v ){
        return find(u) == find(v) ;
    }

}; 

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n  = heights.size();
        int m = heights[0].size();
        DSU d(n*m);

        vector<pair<int,int>>dir = {{1,0},{0,1}};
        vector<tuple<int,int,int>>pq;

        for(int i  = 0;i<n; i++ ){
            for(int j = 0 ; j<m ; j++ ){
                for(auto& it : dir ){
                    int nr = i+it.first; 
                    int nc = j+it.second;

                    if( nr < 0 or nr>=n or nc<0 or nc>=m ) continue;

                    int distance = abs(heights[i][j] - heights[nr][nc]); 

                    pq.push_back({distance , i*m + j , nr*m + nc }); 
                    cout<< distance << " " ; 

                }
            }
        }

        sort(pq.begin() , pq.end()); 
        int ans = 0;

        for(auto& [ dist , node1 , node2 ] : pq ){
            if(!d.connected(node1 , node2 )){
                ans = max(ans , dist );
                d.unite(node1 , node2 );

                if( d.find(0) == d.find(n*m-1)) return ans;
            }
            // cout<< dist << " " ; 
        }   

        return ans ; 
    }
};