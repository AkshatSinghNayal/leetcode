class Solution {
public:

    int solve( int n , vector<int>& dp ){
        //base 

        if(n == 0  ) return 0;
       

        if( dp[n] != -1) return dp[n]; 
        int ans = INT_MAX; 
        for(int i =1 ; i<=n; i++ ){
            long long sum = 1LL*i*(i+1)/2;
            if( sum > n ) break;
            if( sum ==  n) {
                ans = min(ans , i);
            }
            else{
                ans = min(ans , i+1+solve( n-sum , dp)); 
            }
        }
        return dp[n] = ans;
    }

    int minDays(int n) {
        vector<int>dp(n+1, -1 ); 
        return solve(n,dp);
    }
};