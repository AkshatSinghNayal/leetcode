class Solution {
public:

    int solve(vector<vector<int>>&dp, int i , int amount ,vector<int>& coins ){
        //base
        if( amount == 0 ) return 0; 
        if( i  == 0 ){
            if( amount%coins[i] == 0  ) return amount/coins[i]; 
            return INT_MAX-1; 
        }

        if(dp[i][amount] !=-1) return dp[i][amount]; 

        int take = ( coins[i] <= amount ) ? 1+solve(dp , i, amount-coins[i] , coins) : INT_MAX-1; 

        int notTake = solve( dp , i-1 , amount , coins ); 

        return dp[i][amount] = min(take , notTake); 


    }

    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size(); 
        if( amount == 0 ) return 0; 
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result = solve(dp , n-1 , amount ,coins); 
        return result == INT_MAX-1 ? -1 : result;
    }
};