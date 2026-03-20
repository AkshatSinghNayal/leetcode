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
        if( n-1 > V ) return -1; 

        Disjointset d1(n); 
        int count  = 0 ;
        for(auto& it : connections ){
            if(d1.findParent(it[0]) == d1.findParent(it[1])){
                count++; 
                continue;
            }
            d1.unionBySize( it[0] , it[1]);
        }
        
        int distinct = 0;  
        for( int i  = 0  ;i < d1.parent.size()-1; i++ ){
            if( d1.parent[i] ==  i ) {
                distinct++;
            }
        }
        

        if( distinct - 1 <= count ){
            return count-1; 
        }
        return -1 ; 

    }
};