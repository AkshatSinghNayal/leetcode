class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;

        int i = 0 , n = intervals.size(); 

        while( i < n ){
            if(!ans.empty()){
                auto it = ans.back();
                if( max(it[0] , intervals[i][0]) <= min(it[1],intervals[i][1])){
                    ans.pop_back();
                    ans.push_back({min(it[0],intervals[i][0]) , max(it[1],intervals[i][1])}); 
                }
                else{
                     ans.push_back({intervals[i][0] , intervals[i][1]}); 
                }
            }
            else{
                ans.push_back({intervals[i][0] , intervals[i][1]}); 
            }
            i++; 
        }
        return ans;
    }
};