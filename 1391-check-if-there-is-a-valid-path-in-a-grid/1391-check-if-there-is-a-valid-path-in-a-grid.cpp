class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> mp;

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        mp[1] = {{0, -1}, {0, 1}};    // Left, Right
        mp[2] = {{-1, 0}, {1, 0}};    // Up, Down
        mp[3] = {{0, -1}, {1, 0}};    // Left, Down
        mp[4] = {{0, 1}, {1, 0}};     // Right, Down
        mp[5] = {{0, -1}, {-1, 0}};   // Left, Up
        mp[6] = {{0, 1}, {-1, 0}};    // Right, Up

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == m - 1)
                return true;

            // Try every direction from current street
            for (auto [dr, dc] : mp[grid[i][j]]) {

                int nr = i + dr;
                int nc = j + dc;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if (vis[nr][nc])
                    continue;

                // Check whether neighbour connects back
                for (auto [bdr, bdc] : mp[grid[nr][nc]]) {

                    if (nr + bdr == i && nc + bdc == j) {

                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                        break;
                    }
                }
            }
        }

        return false;
    }
};