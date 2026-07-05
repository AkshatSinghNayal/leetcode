class Solution {
public:

    int solve(vector<int>& cost, vector<int>& dp, int i ){
        //base
        if( i< 0 ) return 0;
        
        if(dp[i] != -1 ) return dp[i]; 

        int one = cost[i] + solve(cost , dp , i-1 ); 
        int two = cost[i] + solve(cost , dp , i-2 );

        return dp[i] = min(one , two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n  = cost.size();
        vector<int>dp(n , -1);
        vector<int>dp1(n , -1);

        int ans = solve( cost ,dp  , n-1 );  
        ans = min(ans, solve(cost, dp1 ,n -2 )); 
        return ans;

    }
};