class Solution {
public:

    int change(int amt, vector<int>& coins) {
        int n  = coins.size(); 
        vector<vector<int>>dp(n+1,vector<int>(amt+1 , 0));
        dp[0][0] = 1; 
        for(int i = 1; i<= n ; i++ ){
            for(int amount = 0 ; amount<= amt ; amount++ ){
                long long  take = ( amount>=coins[i-1] ) ? dp[i][amount-coins[i-1]] : 0 ; 
                long long notTake = dp[i-1][amount];
                dp[i][amount] = (take+notTake);
            }

        } 
        return dp[n][amt]; 
    }
};