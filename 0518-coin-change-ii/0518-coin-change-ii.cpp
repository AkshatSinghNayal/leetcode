class Solution {
public:

    int solve(vector<int>& coins , vector<vector<int>>& dp , int i , int amount ){
        //base

        if( i <  0 ){
            return ( amount == 0 ) ? 1 : 0;  ; 
        }
         

        if(dp[i][amount] != -1 ) return dp[i][amount] ; 

        int take = ( amount>=coins[i] ) ? solve( coins , dp , i , amount-coins[i]) : 0 ; 
        int notTake = solve( coins , dp , i-1 , amount ) ;

        return dp[i][amount] = (take+notTake);

    }

    int change(int amount, vector<int>& coins) {
        int n  = coins.size(); 
        vector<vector<int>>dp(n,vector<int>(amount+1 , -1));
        return solve( coins, dp , n-1 , amount); 
        
    }
};