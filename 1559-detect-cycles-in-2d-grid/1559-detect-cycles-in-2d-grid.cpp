#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        visited[x][y] = 1;
        
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            
            if (grid[nx][ny] != grid[x][y])
                continue;
            
            // if not visited → go deeper
            if (!visited[nx][ny]) {
                if (dfs(grid, nx, ny, x, y))
                    return true;
            }
            // if visited and not parent → cycle found
            else if (nx != px || ny != py) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }
        
        return false;
    }
};