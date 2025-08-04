class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ; 
        sort(intervals.begin(), intervals.end());
        int j = 1; int k = 0;

        for(int i = 0; i < intervals.size(); ) {
            int start = intervals[i][k];
            int end = intervals[i][j];

            // Keep merging while next interval overlaps
            while((i+1) < intervals.size() && end >= intervals[i+1][k]) {
                end = max(end, intervals[i+1][j]);
                i++;
            }

            ans.push_back({start, end});
            i++;  // Move to next interval
        }

        return ans;
    }
};
