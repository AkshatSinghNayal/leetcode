class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(); 
        int m= waterStartTime.size(); 
        int mini = INT_MAX; 

        for(int i  = 0 ;i<n ;i++ ){
            int dist = landStartTime[i]+landDuration[i]; 
            for(int j =0;j<m ;j++ ){
                if(dist>=waterStartTime[j]){
                    mini = min(mini, dist+ waterDuration[j]); 
                }
                else{
                    mini = min( waterStartTime[j]+waterDuration[j] , mini ); 
                }
            }
        }

        for(int i  = 0 ;i<m ;i++ ){
            int dist = waterStartTime[i]+waterDuration[i]; 
            for(int j =0;j<n ;j++ ){
                if(dist>=landStartTime[j]){
                    mini = min(mini, dist+ landDuration[j]); 
                }
                else{
                    mini = min( landStartTime[j]+landDuration[j] , mini ); 
                }
            }
        }

        return mini ; 
    }
};