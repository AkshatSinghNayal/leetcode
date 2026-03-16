class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

        pq.push({1, {0, 0}});
        ans[0][0] = 1;

        int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

        while (!pq.empty()) {
            auto [dist, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            // reach last → break and return
            if (r == n-1 && c == n-1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && ans[nr][nc] > dist + 1) {

                    ans[nr][nc] = dist + 1;
                    pq.push({ans[nr][nc], {nr, nc}});
                }
            }
        }

        return -1;
    }
};
