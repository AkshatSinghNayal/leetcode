class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        for (auto &s : sources) {
            int r = s[0], c = s[1], color = s[2];
            grid[r][c] = color;
            q.push({r, c});
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int sz = q.size();

            map<pair<int,int>, int> nextColor;

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                        nextColor[{nr, nc}] = max(nextColor[{nr, nc}], grid[r][c]);
                    }
                }
            }

            for (auto &[pos, color] : nextColor) {
                int r = pos.first, c = pos.second;
                grid[r][c] = color;
                q.push({r, c});
            }
        }

        return grid;
    }
};