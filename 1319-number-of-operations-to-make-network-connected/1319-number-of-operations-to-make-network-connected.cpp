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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int V = connections.size() ; 
        Disjointset d(V);
        if(n-1 > V ) return -1;
        int extra = 0; int setted = 1;

        for(auto& it : connections ){
            int node1  = it[0]; 
            int node2 = it[1]; 

            if( d.findParent(node1) ==  d.findParent(node2)){
                extra++; 
                continue;  
            } 

            d.unionBySize( node1 , node2 ); 
            setted++; 
        }

        int needed =  n-setted; 
        return needed;

    }
};