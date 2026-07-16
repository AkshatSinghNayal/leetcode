class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size(); 
        if( n < d ) return -1; 
        vector<vector<int>>dp(n+1 , vector<int>(d+1 , -1)); 
        int maxii = INT_MIN;
        for(int i = n-1; i>= 0 ;i-- ){
            maxii = max(maxii , job[i]);
            dp[i][1] = maxii;
        }

        for( int idx =n-1; idx>=0 ;idx-- ){
            for(int day =2 ; day<= d ; day++ ){

                int maxi = job[idx] , result = INT_MAX; 

                for(int i = idx ; i<=n-day; i++ ){
                    maxi = max(maxi , job[i]); 
                    int temp = maxi + dp[i+1][day-1]; 
                    result = min(result, temp);
                }
                dp[idx][day] = result;
            }
        }
        return dp[0][d]; 
    }
};