class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto &in : intervals){
            if(res.empty() || res.back()[1] < in[0]) res.push_back(in);
            else res.back()[1] = max(res.back()[1], in[1]);
        }
        return res;
    }
};