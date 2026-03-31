class Solution {
public:

    // int dp1( int n , vector<int>&dp){
    //     // if( n<0 ) return 0; 
    //     if( n <=1  ) return 1;
    //     if( dp[n]!= -1 ) return dp[n]; 
    //     int one = dp1(n-1,dp);
    //     int two = dp1(n-2,dp);

    //     return dp[n]=(one+two);

    // }


    int climbStairs(int n) {
        // vector<int> dp(n+1 ,0); 
        // dp[0] = 1; 
        // dp[1] = 1;
        int prev = 1 , prev2 = 1; 
        for(int i = 2; i<=n; i++ ){
            int temp = prev+prev2; 
            prev2 = prev; 
            prev = temp;
        }
        return prev;
    }
};