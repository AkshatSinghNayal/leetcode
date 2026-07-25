class Solution {
public:

        unordered_map<int,vector<pair<int,int>>> mp; 

        

    bool solve(vector<vector<int>>& grid , int n , int m , int i , int j,vector<vector<int>>&vis){
        //base 
        if( i == n-1 and j ==  m-1 ) return true;
        if( i<0 or j<0 or i>=n or j>=m ) return false;
        vis[i][j] = 1; 

        for(auto& it : mp[grid[i][j]]){
            auto [ nr , nc ] = it ;
            nr+=i; nc+=j; 
            if(nr>=0 and nc>=0 and nr<n and nc < m and vis[nr][nc] == -1){
                for(auto& temp : mp[grid[nr][nc]]){
                    auto [ nr2 , nc2 ] = temp; 
                    if(nr2+nr == i and nc2+nc == j ){
                        if(solve(grid, n, m, nr, nc, vis)){
                            return true;
                        } 
                    }
                }
            }
        }

        return false; 
    }


    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        mp[1] = {{0, -1}, {0, 1}};   // Left, Right
        mp[2] = {{-1, 0}, {1, 0}};   // Up, Down
        mp[3] = {{0, -1}, {1, 0}};   // Left, Down
        mp[4] = {{0, 1}, {1, 0}};    // Right, Down
        mp[5] = {{0, -1}, {-1, 0}};  // Left, Up
        mp[6] = {{0, 1}, {-1, 0}};   // Right, Up
        vector<vector<int>>vis(n,vector<int>(m , -1)); 

        

        auto ans =  solve(grid,  n ,  m ,0,0,vis); 
        for(auto& it : vis ){
            for(int i = 0 ;i<it.size(); i++ ){
                cout<<it[i]<<" "; 
            } 
            cout<<endl;
        }

        return ans; 
    }
};