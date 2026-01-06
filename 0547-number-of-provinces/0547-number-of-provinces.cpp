class Solution {
public:
    void dfs( int index , vector<int>& visited ,vector<vector<int>>& vis ){
        visited[index ]=1 ; 
        for( auto &it : vis[index]){
            if(!visited[it]){
                dfs( it , visited , vis ); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> vis(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    vis[i].push_back(j);
                    vis[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for(int i =0 ; i< n; i++){
            if(!visited[i]){
                count++; 
                dfs( i, visited, vis ); 
            }
        }

        
        return count;
    }
};
