class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans; 
        bool found = false;
        int i = 0;

        for(auto& it : intervals ){
            int start = newInterval[0], end = newInterval[1]; 

            // newInterval comes before current interval
            if(end < it[0]) {
                ans.push_back(newInterval);
                found = true;
                break;
            }

            // overlap
            if(start <= it[1] && end >= it[0]) {
                start = min(start, it[0]);              // FIX
                end = max(end, it[1]);
                found = true;
                i++;

                while(i < intervals.size() && end >= intervals[i][0]) {
                    end = max(end, intervals[i][1]);
                    i++;
                }

                ans.push_back({start, end}); 
                break;
            }

            ans.push_back(it); 
            i++; 
        }

        if(!found) {
            ans.push_back(newInterval);
        }

        while(i < intervals.size()) {
            ans.push_back(intervals[i++]); 
        }

        return ans;
    }
};