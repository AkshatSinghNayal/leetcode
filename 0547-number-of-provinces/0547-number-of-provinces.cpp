class Disjoint{
    public: 
    vector<int>size , parent; 

    Disjoint(int V  ){
        size.resize(V+1 , 1); 
        parent.resize(V+1); 

        for(int i  = 0 ;i<=V ; i++ ) parent[i] = i; 
    }

    int findParent( int n ){

        if( parent[n] == n  ) return n; 
        return parent[n] = findParent(parent[n]); 
    }

    void unionBySize( int u , int v ){
        int NodeA = findParent(u); 
        int NodeB = findParent(v); 

        if( NodeA == NodeB ) return ; 

        if( size[NodeA] > size[NodeB]){
            parent[NodeB ] = NodeA;
            size[NodeA] +=size[NodeB];
        }
        else{
            parent[NodeA] = NodeB;
            size[NodeB] +=size[NodeA];
        }

    }
}; 

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        Disjoint d(n);

        for(int i = 0; i< n; i++ ){
            for(int j  = 0 ;j < n; j++ ){
                if(isConnected[i][j] ==  1 ){
                    d.unionBySize( i , j) ; 
                }
            }
        }
        int count = 0; 
        for(int i  = 0; i< n ; i++ ){
            if( d.parent[i] == i ) count++; 
        }

        return count; 
    }
};