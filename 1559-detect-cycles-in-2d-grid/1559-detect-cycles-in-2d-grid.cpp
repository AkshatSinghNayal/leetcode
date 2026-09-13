class Disjoint{
    public:
    vector<int>size,parent;

    Disjoint( int V ){
        size.resize(V+1); 
        parent.resize(V+1); 

        for(int i  = 0 ; i<=V ; i++ ){
            parent[i] = i;
        }
    }

    int findParent( int u ){
        if(parent[u] ==  u ) return u ;
        return parent[u] = findParent(parent[u]);
    }

    bool unionBySize( int u , int v ){
        int pu = findParent(u) , pv = findParent(v);

        if( pu == pv ) return true;
        
        if( size[pu] >= size[pv]){
            size[pu]+=size[pv]; 
            parent[pv] = pu;
        }
        else{
            size[pu] += size[pv]; 
            parent[pu]=pv;
        }
        return false;
    }
}; 


class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {

        vector<pair<int,int>>dir= {{1,0},{-1,0},{0,-1},{0,1}}; 

        int n = grid.size() , m =grid[0].size(); 
        vector<bool>Vis(n*m+1 , false);
        Disjoint d(n*m+1); 
        for(int i  = 0 ;i< n; i++ ){
            for(int j = 0 ;j<m ; j++ ){

                int node = i*m+j;
                Vis[node]=  true; 
                char ch = grid[i][j]; 

                for(auto& it : dir ){
                    auto[ row , col ] = it ;
                    int newR = row+i; 
                    int newC = col+j;

                    if( newR<0 or newC <0 or newR >= n or newC >=m or grid[newR][newC] != ch  or !Vis[newR*m + newC] ) continue;

                    if(d.unionBySize(node , newR*m+newC)) return true;


                }

            }
        }
        return false;
    }
};