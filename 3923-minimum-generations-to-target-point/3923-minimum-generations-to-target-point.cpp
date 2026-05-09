class Solution {
public:
    struct Point {
        int x, y, z;

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    struct Hash {
        size_t operator()(const Point& p) const {
            return ((1LL * p.x * 1000003 + p.y) * 1000003 + p.z);
        }
    };

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        
        Point tar = {target[0], target[1], target[2]};

        unordered_set<Point, Hash> seen;
        vector<Point> all;

        // generation 0
        for (auto &p : points) {
            Point cur = {p[0], p[1], p[2]};

            if (cur == tar) return 0;

            if (!seen.count(cur)) {
                seen.insert(cur);
                all.push_back(cur);
            }
        }

        int generation = 0;

        while (true) {
            generation++;

            vector<Point> newlyAdded;

            int n = all.size();

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {

                    // distinct coordinates only
                    if (all[i] == all[j]) continue;

                    Point c = {
                        (all[i].x + all[j].x) / 2,
                        (all[i].y + all[j].y) / 2,
                        (all[i].z + all[j].z) / 2
                    };

                    if (!seen.count(c)) {

                        if (c == tar)
                            return generation;

                        seen.insert(c);
                        newlyAdded.push_back(c);
                    }
                }
            }

            // no new points formed
            if (newlyAdded.empty())
                return -1;

            for (auto &p : newlyAdded)
                all.push_back(p);
        }

        return -1;
    }
};