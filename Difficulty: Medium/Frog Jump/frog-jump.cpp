class Solution {
  public:
    
    int solve(vector<int>& height , vector<int>& dp , int n ){
        if( n<0 ) return INT_MAX; 
        if( n == 0 ) return 0; 
        
        if( dp[n] != -1 ) return dp[n]; 
        
        int move1 =  abs(height[n]- height[n-1])+solve(height , dp , n-1 ) ; 
        int move2 = (n-2>= 0) ? abs(height[n]-height[n-2])+solve(height, dp , n-2) : INT_MAX ; 
        
        return dp[n] = min( move1 , move2 ); 
        
    }
  
    int minCost(vector<int>& height) {
        // Code here
        int n =  height.size() ; 
        vector<int> dp(n , -1); 
        return solve( height , dp , n-1 ); 
    }
};