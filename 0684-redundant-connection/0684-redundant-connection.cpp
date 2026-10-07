class DSU{
    public:
    vector<int>parent,size;
    vector<pair<int,int>>ans;

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

        if( pu == pv ) {
            ans.push_back({u,v});
            return;
        }

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n);

        for(auto& it : edges )   {
            int a = it[0] , b = it[1];   
            d.unite( a, b );
        }

        int size = d.ans.size();
            vector<int>ok;
            ok.push_back(d.ans[size-1].first);
            ok.push_back(d.ans[size-1].second);
            return ok;
    }
};