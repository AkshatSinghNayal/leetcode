class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        int start = newInterval[0], end = newInterval[1];

        // Add intervals completely before newInterval
        while (i < n && intervals[i][1] < start) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }

        ans.push_back({start, end});

        // Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
