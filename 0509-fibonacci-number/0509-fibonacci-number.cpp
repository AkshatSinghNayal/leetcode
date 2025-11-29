class Solution {
public:

    int helperFunction( vector<int>& dp , int n){
        if(n<=1) return n ; 

        if(dp[n] != -1){
            return dp[n]; 
        }

        return dp[n] = helperFunction( dp , n-1 ) + helperFunction(dp , n-2 ) ;
    }

    int fib(int n) {

        vector<int> dp(n+1 , -1 ); 
       return  helperFunction( dp, n ) ; 
        

    }
};