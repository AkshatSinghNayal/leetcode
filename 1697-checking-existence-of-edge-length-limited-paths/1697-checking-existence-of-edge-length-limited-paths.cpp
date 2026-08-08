
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

        // FIX 2: Store queries with original indices: {limit, nodeA, nodeB, originalIndex}
        vector<tuple<int,int,int,int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<bool> ans(queries.size()) ; 
        int edgeIdx = 0;

        // FIX 3: Process queries in increasing order of limit
        for(auto& it : sortedQueries ){
            auto [limit, nodeA, nodeB, originalIdx] = it;

            while (edgeIdx < m && get<0>(edges[edgeIdx]) < limit) {
                d.unionBySize(get<1>(edges[edgeIdx]), get<2>(edges[edgeIdx]));
                edgeIdx++;
            }

            ans[originalIdx] = (d.find(nodeA) == d.find(nodeB));
        }

        return ans; 
    }
};