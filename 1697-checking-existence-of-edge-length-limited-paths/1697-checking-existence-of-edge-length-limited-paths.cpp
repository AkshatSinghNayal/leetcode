
class DisjointSet{
    public: 
    vector<int> size , parent; 
    DisjointSet(int V ){
        size.resize(V+1 , 1 ); 
        parent.resize(V+1);
         
        for(int i  = 0 ;i<= V ; i++ ){
            parent[i] =  i; 
        }
    }

    int find( int u ){
        if( parent[u] ==  u ) return u ;
        return parent[u] = find(parent[u]); 
    }

    void unionBySize(int v , int u){
        int pa = find(v) , pb = find(u); 

        if(pa  == pb ) return ; 

        if(size[pa] >= size[pb]){
            parent[pb] = pa;
            size[pa]+=size[pb]; 
        }
        else{
            parent[pa]=  pb ; 
            size[pb]+=size[pa]; // FIX 1: Corrected size accumulation
        }
    }
}; 

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet d(n); 

        vector<tuple<int,int,int>> edges; 
        int m = edgeList.size(); 
        for(int i  = 0 ;i<m ;i++ ){ 
            int weight = edgeList[i][2]; 
            int nodeB = edgeList[i][1]; 
            int nodeA = edgeList[i][0]; 

            edges.push_back({weight ,nodeA , nodeB}) ; 
        }

        sort(edges.begin() , edges.end()); 

        vector<tuple<int,int,int,int>> query; 

        int i  =0 ; 
        for(auto& it : queries){
            int weight = it[2]; 
            int a = it[1]; 
            int b  = it[0]; 
            query.push_back({weight,a,b,i}); i++; 
        }
        sort(query.begin() , query.end()); 

        i =0; 
        vector<bool>ans(query.size()); 
        for(auto& it : query ){
            auto [ weight , a , b , idx ] = it; 

            while( i<edges.size() and weight > get<0>(edges[i])){
                d.unionBySize( get<1>(edges[i]) , get<2>(edges[i])); 
                i++; 
            }
            ans[idx] = (d.find(a) == d.find(b)); 


        }
        return ans; 
    }
};