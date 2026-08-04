class Disjointset {
public:
    vector<int> size, parent;

    Disjointset(int V) {
        size.resize(V + 1, 1);
        parent.resize(V + 1);

        for (int i = 0; i <= V; i++)
            parent[i] = i;
    }

    int findParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize(int u, int v) {
        int NodeA = findParent(u);
        int NodeB = findParent(v);

        if (NodeA == NodeB)
            return;

        if (size[NodeA] > size[NodeB]) {
            parent[NodeB] = NodeA;
            size[NodeA] += size[NodeB];
        } else {
            parent[NodeA] = NodeB;
            size[NodeB] += size[NodeA];
        }
    }
};


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& points) {
            
        int n  = points.size(); 
        vector<vector<int>>edges = points;
        Disjointset d(V);

        sort(edges.begin() , edges.end() , [&](auto a , auto b ){
            return a[2]<b[2]; 
        }); 
        int countOfEdges = 0; int minCost = 0; 

        for(auto& it  : edges ){
            
            int u = it[0], v = it[1] , distance = it[2]; 
            
            if( d.findParent(u) != d.findParent(v)){
                d.unionBySize(u,v ); 

                countOfEdges++; 
                minCost+=distance;

                if( countOfEdges == V-1 ) break;
            }
        }
        return minCost; 
        
    }
};