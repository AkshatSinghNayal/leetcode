class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end increasingly, and if tie, by start decreasing
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<int> chosen;  // store selected points

        for (auto &interval : intervals) {
            int l = interval[0], r = interval[1];

            // Count how many chosen points lie in [l, r]
            int cnt = 0;
            for (int i = (int)chosen.size() - 1; i >= 0 && chosen[i] >= l; --i) {
                if (chosen[i] <= r) cnt++;
                if (cnt == 2) break;
            }

            if (cnt == 2) continue;

            if (cnt == 1) {
                // Add one more point: r
                chosen.push_back(r);
            } else {
                // cnt == 0, add two points: r-1, r
                chosen.push_back(r - 1);
                chosen.push_back(r);
            }
        }

        return chosen.size();
    }
};
