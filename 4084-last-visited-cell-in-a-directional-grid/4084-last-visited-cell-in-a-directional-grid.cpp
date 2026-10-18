class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n  = grid.size() , m = grid[0].size(); 
        vector<vector<int>>vis(n,vector<int>(m , -1)); 
        queue<pair<int,int>>q; 
        unordered_map<char,pair<int,int>>mp; 
        mp['R'] = {0,1}; 
        mp['L'] = {0,-1}; 
        mp['U'] = {-1,0}; 
        mp['D'] = {1,0}; 
        q.push({0,0}); 
        while(!q.empty()){
            auto [ row , col  ]= q.front() ; q.pop(); 
            vis[row][col] = 1;
            char ch = grid[row][col]; 

            if( row+mp[ch].first <0 or row+mp[ch].first>=n or col+mp[ch].second <0 or col+mp[ch].second>=m or vis[row+mp[ch].first][col+mp[ch].second] != -1 ) return { row , col }; 

            q.push({row+mp[ch].first , col+mp[ch].second}); 

        }
        return {-1,-1}; 
    }
};