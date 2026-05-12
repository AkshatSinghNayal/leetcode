class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size(); 
        if( amount == 0 ) return 0; 
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX-1));
        dp[0][0] =0;
        for(int i = 1 ; i<= n; i++ ){
            for(int j = 0 ; j<=amount ; j++ ){
                int take = ( coins[i-1] <= j ) ? 1+dp[i][j-coins[i-1]]: INT_MAX-1; 
                int notTake = dp[i-1][j];

                dp[i][j] = min(take,notTake); 
            }
        }

        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
};