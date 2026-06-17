class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> paths;
        queue<vector<int>> q;

        q.push({0});

        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();

            int node = path.back();

            if (node == n - 1) {
                paths.push_back(path);
                continue;
            }

            for (int next : graph[node]) {
                vector<int> newPath = path;
                newPath.push_back(next);
                q.push(newPath);
            }
        }

        return paths;
    }
};