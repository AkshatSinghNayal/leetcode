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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0 ; int total = 1; 
        DSU d(n);

        for(auto& it : connections ){
            int node1 = it[0] , node2 = it[1]; 

            if(!d.connected(node1 , node2)){
                d.unite(node1 , node2 );
                total++; 
            }
            else{
                count++;
            }

        }
        
        cout<< total << " " << count; 
        return ( total+count < n ) ? -1 : min( count , n-total);
    }
};