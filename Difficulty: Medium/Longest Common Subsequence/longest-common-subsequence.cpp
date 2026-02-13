class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n= s1.size()  , m = s2.size() ; 
        vector<vector<int>>dp(n+1 , vector<int>(m+1,0)); 
        
        for( int i =1 ; i<=n ;i++){
            for( int j =  1 ; j<=m ; j++ ){
                dp[i][j] = (s1[i-1] == s2[j-1] ) ? 1+ dp[i-1][j-1] : max(dp[i-1][j] , dp[i][j-1]); 
            }
        }
        return dp[n][m]; 
        
    }
};
