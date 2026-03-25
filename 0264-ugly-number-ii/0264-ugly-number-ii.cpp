class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int i1 = 0, i2 = 0, i3 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int temp  = min({ dp[i1]*2 , dp[i2]*3  , dp[i3]*5}); 
            dp[i] = temp; 
            if(  temp == dp[i1]*2 ) i1++;
            if( temp == dp[i2]*3 ) i2++;
            if(temp == dp[i3]*5 ) i3++;
        }
        return dp[n - 1];
    }
};