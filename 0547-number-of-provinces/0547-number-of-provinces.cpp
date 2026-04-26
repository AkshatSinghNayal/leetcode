class Solution {
public:

    void dfs(vector<vector<int>>& list , int i, vector<int>& vis ){
        vis[i] =1 ; 
        for(auto& it : list[i]){
            if(vis[it] ==-1 ){
                dfs(list , it , vis); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size(); 
        vector<vector<int>>list(n); 

        for(int i  = 0;i < n ;i++ ){
            for(int j = 0 ; j<n; j++ ){
                if(i!=j and grid[i][j] == 1 ){
                    list[i].push_back(j); 
                    list[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,-1); int count  = 0 ; 
        for(int i= 0; i< n ; i++ ){
            if(vis[i] == -1){
                dfs(list , i, vis);
                count++; 
            }
        }

        return count;

    }
};