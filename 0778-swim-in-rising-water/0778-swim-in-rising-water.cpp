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
    int swimInWater(vector<vector<int>>& grid) {
        int n =  grid.size(); 
        Disjointset d(n*n); 
        vector<vector<int>>dir = {{1,0},{0,1}}; 
        vector<tuple<int,int,int>>edge;
        // edge.push_back({grid[i][j],0,0}); 

        for(int i = 0 ;i< n; i++ ){
            for(int j = 0 ; j< n ;j++ ){
                int currentCost = grid[i][j]; 

                for(auto& it : dir ){
                    int nr = i+it[0]; 
                    int nc = it[1]+j; 

                    if( nr >=0 and nc>=0 and nr<n and nc <n ){
                        if( currentCost <= grid[nr][nc]){
                            edge.push_back({grid[nr][nc] , i*n+j , nr*n+nc }); 
                        }
                        else{
                            edge.push_back({currentCost , i*n+j , nr*n+nc }); 
                        }

                    }
                }
            }
        }
        sort(edge.begin() ,edge.end());
        // for(auto& it : edge){
        //     cout << get<0>(it) << " " ; 
        // }

        int check = (n*n) -1 ; 
        if (n == 1) return grid[0][0];
        for(auto& it : edge ){
            auto [ cost , nodeA , nodeB ] = it; 
                d.unionBySize(nodeA , nodeB ); 
            if(d.findParent(0) == d.findParent(check)) return cost;
            
            
        }
        return -1;
    }
};