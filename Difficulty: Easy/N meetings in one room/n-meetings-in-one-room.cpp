class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
    vector<pair<int,int>> meetings;
    for(int i=0; i<n; i++)
        meetings.push_back({start[i], end[i]});

    // sort by end time
    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b){ return a.second < b.second; });
         
         int count = 1;
          
           int ed = meetings[0].second; 
           int i = 1 ; 
       while(i<n){
           
         int  st = meetings[i].first; 
           if(st>ed){
               count++;
               ed = meetings[i].second;
               
               
           }
           
           
           i++;
       }
       return count;
    }
};