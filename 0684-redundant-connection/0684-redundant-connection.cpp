class Disjointset{
    public :
    vector<int> size , parent ; 

    Disjointset(int V ){
        size.resize(V+1 , 1 ); 
        parent.resize(V+1 ); 


        for( int i  = 0; i<=V ; i++ ){
            parent[i]= i ; 
        }
    }

    int findParent( int n ){
        if(parent[n] ==  n ) return n ; 
        return parent[n]= findParent(parent[n]);
    }

    void unionBySize( int u , int v ){
        int NodeA = findParent(u); 
        int NodeB = findParent(v); 

        if( NodeA == NodeB ) return ; 

        if( size[NodeA] > size[NodeB]){
            parent[NodeB]= NodeA; 
            size[NodeA]+=size[NodeB];
        }
        else{
            parent[NodeA] = NodeB; 
            size[NodeB] +=  size[NodeA];
        }
    }

}; 


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n  = edges.size();
        Disjointset d(n);
        for(auto& it : edges){
            if(d.findParent(it[0]) == d.findParent(it[1])){
               return { it[0] , it[1]}; 
            }
            else{
                d.unionBySize( it[0] , it[1]); 
            }
        }

        return {-1,-1}; 
    }
};