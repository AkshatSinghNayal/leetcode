class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ; 
        sort(intervals.begin(),intervals.end());
        int j = 0 ; int k = 1 ;

        for( int i = 0; i<intervals.size(); i++){
            int start = intervals[i][j]; 
            bool flag = true;
            int end = intervals[i][k]; 
            while(i+1<intervals.size() && end>= intervals[i+1][j]){
                end=max(end,intervals[i+1][k]);
                i++;
            }
            ans.push_back({start,end});
           
        }
        return ans ; 
    }
};