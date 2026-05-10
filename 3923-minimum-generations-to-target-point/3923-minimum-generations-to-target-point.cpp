class Solution {
public:

    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v) {
                h ^= std::hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        unordered_set<vector<int>, VectorHash> all(points.begin(), points.end());

        if (all.count(target)) return 0;
        if (all.size() <= 1) return -1;

        vector<vector<int>> current = points;

        int k = 0;

        while (true) {

            vector<vector<int>> next;
            unordered_set<vector<int>, VectorHash> addedThisRound;

            int n = current.size();

            for (int i = 0; i < n-1; i++) {
                for (int j = i + 1; j < n; j++) {

                    vector<int> mid(3);

                    for (int d = 0; d < 3; d++) {
                        mid[d] = (current[i][d] + current[j][d]) / 2;
                    }

                    if (mid == target) return k + 1;

                    // only add new points
                    if (!all.count(mid)) {
                        all.insert(mid);
                        addedThisRound.insert(mid);
                        next.push_back(mid);
                    }
                }
            }

            if (next.empty()) return -1;

            // move to next generation
            current.insert(current.end(), next.begin(), next.end());

            k++;
        }
    }
};