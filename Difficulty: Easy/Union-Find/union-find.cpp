// User function Template for C++

class Solution {
  public:
    int find( int x , int par[]){
        if(par[x] == x ) return par[x]; 
        return par[x] = find(par[x] , par); 
    }
    // Function to merge two nodes a and b.
    void union_(int a, int b, int par[], int rank1[]) {
        int rootA = find(a, par);
        int rootB = find(b, par);

        if (rootA == rootB) return;

        if (rank1[rootA] < rank1[rootB]) {
            par[rootA] = rootB;
        }
        else if (rank1[rootA] > rank1[rootB]) {
            par[rootB] = rootA;
        }
        else {
            par[rootB] = rootA;
            rank1[rootA]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
        
       return find(x , par ) == find(y , par ); 
    }
};