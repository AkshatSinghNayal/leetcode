class Disjointset{
public:
    vector<int> parent , size;

    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u , int v){
        int rootA = findParent(u);
        int rootB = findParent(v);

        if(rootA == rootB) return;

        if(size[rootA] < size[rootB]){
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else{
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();
        Disjointset d1(V);

        // shift +1 while calling union
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1){
                    d1.unionBySize(i+1 , j+1);
                }
            }
        }

        int count = 0;

        // only check 1 to V
        for(int i = 1; i <= V; i++){
            if(d1.parent[i] == i)
                count++;
        }

        return count;
    }
};
