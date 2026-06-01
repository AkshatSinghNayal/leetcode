// User function Template for C++

class Solution {
  public:
    
    int solve(vector<int>& price , vector<vector<int>>&dp , int i , int amount ){
        //base
        if( i< 0 ){
            return 0; 
        }
        
        if(dp[i][amount]!= -1 ) return dp[i][amount]; 
        int take = ( amount >= i+1 ) ? price[i] + solve( price , dp , i , amount-i-1 ) : 0; 
        int notTake = solve(price ,dp , i-1 , amount ); 
        
        return dp[i][amount] = max( take , notTake );
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1 , -1)); 
        return solve(price , dp , n-1 , n ); 
        
    }
};