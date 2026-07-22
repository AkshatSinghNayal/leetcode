class Solution {
public:
    // int solve(int i , int minProfit,vector<int>& group, vector<int>& profit ,int n ){
    //     //base 

    //     if( i < 0 ){
    //         return minProfit == 0 ? 1 : 0 ; 
    //     }
        
    //     if(dp[i][minProfit][n] != -1 ) return dp[i][minProfit][n] ; 

    //     long long  take = (n>= group[i] and minProfit >=0 ) ? solve(i-1, max(0,minProfit-profit[i]), group, profit ,  n-group[i]) : 0 ; 
    //     long long  notTake = solve(i-1,minProfit , group , profit , n ); 

    //     return dp[i][minProfit][n] = ( 0LL+take + notTake )%MOD;  

    // }


    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int m = group.size();
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < m; i++) {

        for (int members = n; members >= group[i]; members--) {

            for (int p = minProfit; p >= 0; p--) {

                int take = dp[members - group[i]][max(0, p - profit[i])];

                dp[members][p] = (dp[members][p] + take) % MOD;
            }
        }
    }

    return dp[n][minProfit];
}

};