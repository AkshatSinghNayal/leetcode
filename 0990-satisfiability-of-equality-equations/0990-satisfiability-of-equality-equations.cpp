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
    bool equationsPossible(vector<string>& equations) {
        int V = equations.size(); 
        Disjointset d(26); 
        sort(equations.begin(), equations.end(), [](string &a, string &b) {
    return a[1] > b[1];
});

        for(int i  = 0 ;i<V ;i++ ){
            int node1 = equations[i][0]-'a'+1; 
            int node2 = equations[i][3]-'a'+1; 
            bool equal = ( equations[i][1] =='=') ? true : false;

            if( d.findParent(node1) == d.findParent(node2) and !equal ){
                return false;
            }

            if(equal){
                d.unionBySize(node1 , node2 );
            }
            


        }
        return true;
    }
};