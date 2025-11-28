class Solution {
public:

    int findFib( int  n   , vector<int>& dp){
        
        if( dp[n]!=-1 ){
            return dp[n] ; 
        }

        int left = findFib( n-1 , dp); 
        int right= findFib(n-2  , dp ) ; 

        
         
        return dp[n]= right+left ; 

     
    }

    int fib(int n) {
        vector<int> dp(n+1 , -1 ) ; 
        if( n== 0  || n== 1 ) return n; 
        dp[0]= 0 ; 
        dp[1]=1 ; 
        findFib( n , dp ) ;

        return dp[n] ;
    }
};