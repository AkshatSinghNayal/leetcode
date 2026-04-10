class Solution {
public:

    int solve(vector<vector<int>>&dp, vector<int>& coins, int amount , int i   ){
        // base 

        if( i == 0  ){
            if( amount%coins[i] ==  0 ){
                return amount/coins[i]; 
            }
            return 1e9; 
        }

        if( dp[i][amount]!=-1 ) return dp[i][amount];  
        long long take = 1e9 ;  
        if(amount>= coins[i] ) {take =1+ solve( dp , coins , amount - coins[i] , i ); }

        long long notTake = solve( dp , coins , amount , i-1 ); 

        return dp[i][amount] = min(take , notTake ); 
    }

    int coinChange(vector<int>& coins, int amount) {
        int n =  coins.size(); 
        vector<vector<int>>dp( n , vector<int>(amount+1  ,-1 )); 
        int ans = solve( dp , coins , amount , n-1 ); 
        return (ans == 1e9 ) ? -1 : ans ; 
    }
};