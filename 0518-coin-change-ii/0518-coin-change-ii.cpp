class Solution {
public:

    // int solve(vector<vector<int>>&dp , int i , int amount , vector<int>& coins ){
    //     //base
    //     if( i == 0 ){
    //         if( amount == 0 ) return 1; 
    //         else if( amount%coins[i] == 0  ) return 1 ; 
    //         return 0; 
    //     }
    //     if( amount <0 ) return 0; 

        
    //     if( dp[i][amount] != -1 ) return dp[i][amount]; 

    //     int take = 0; 
    //     if(coins[i]<=amount){
    //         take = solve( dp , i , amount-coins[i] , coins );
    //     }
    //     int notTake = solve( dp , i-1 , amount , coins );

    //     return dp[i][amount] = (take+notTake); 
    // }

    int change(int amount, vector<int>& coins) {
        int n  = coins.size(); 
        vector<vector<int>>dp( n , vector<int>(amount+1 , -1)); 

        for(int i =0 ; i<= amount ; i++ ){
            dp[0][i] = (i%coins[0] == 0 ) ? 1 : 0; 
        }
        dp[0][0] =1;

        for(int i = 1; i<n ;i++ ){
            for(int j = 0; j<= amount ;j++ ){

                int take = 0; 
                if(coins[i]<=j){
                    take = dp[i][j-coins[i]]; 
                }
                int notTake = dp[i-1][j]; 
                dp[i][j] = (0LL+take+notTake); 
            }
        }
        return dp[n-1][amount]; 
    }
};