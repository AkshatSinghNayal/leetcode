class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0; 
        sort(intervals.begin(),intervals.end());
        
        for( int i  =0 ; i<intervals.size(); i++){
            
           
            int end = intervals[i][1];
            while(i+1<intervals.size() && end>intervals[i+1][0]){
              end = min(end,intervals[i+1][1]);
              count++; 
              i++;
              
            }

        }
        return count ; 
    }
};