class Solution {
public:
    int dp[301][11]; 

    int solve(vector<int>& job , int idx , int day , int n ){
        //base; 
        if( idx>=n and day >1 ) return INT_MAX;
        if( day == 1 ){
            return *max_element(job.begin()+idx , job.end());
        }
        if(dp[idx][day] != -1 ) return dp[idx][day]; 

        int maxi = job[idx] , result = INT_MAX; 

        for(int i = idx ; i<=n-day; i++ ){
            maxi = max(maxi , job[i]); 
            int temp = maxi + solve(job , i+1 , day-1 , n); 
            result = min(result, temp);
        }
        return dp[idx][day] = result;
    }

    int minDifficulty(vector<int>& job, int d) {
        int n = job.size(); 
        if( n < d ) return -1; 
        memset(dp, -1 , sizeof(dp));
        return solve(job , 0 , d ,n ); 
    }
};