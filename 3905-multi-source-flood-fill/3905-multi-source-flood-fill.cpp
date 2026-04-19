class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // {time, color, row, col}
        using T = tuple<int,int,int,int>;
        queue<T> q;

        // initialize
        for (auto &s : sources) {
            int r = s[0], c = s[1], color = s[2];
            q.push({0, color, r, c});
            grid[r][c] = color;
            dist[r][c] = 0;
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [time, color, r, c] = q.front();
            q.pop();

            for (auto &d : dir) {
                int nr = r + d[0], nc = c + d[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    // first time reaching
                    if (dist[nr][nc] > time + 1) {
                        dist[nr][nc] = time + 1;
                        grid[nr][nc] = color;
                        q.push({time + 1, color, nr, nc});
                    }
                    // same time → take max color
                    else if (dist[nr][nc] == time + 1 && grid[nr][nc] < color) {
                        grid[nr][nc] = color;
                        q.push({time + 1, color, nr, nc});
                    }
                }
            }
        }

        return grid;
    }
};