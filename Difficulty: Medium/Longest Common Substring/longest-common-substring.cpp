class Solution {
  public:
    int longCommSubstr(string& text1, string& text2) {
        int n = text1.size() , m = text2.size() ;
        vector<vector<int>>dp( n+1 , vector<int>( m+1 , 0)); 

        for( int i=1; i<= n ; i++ ){
            for(int j=1 ; j<= m ; j++ ){
                dp[i][j] = ( text1[i-1] == text2[j-1]) ? 1+dp[i-1][j-1] : 0;
            }
        }
        int maxi  = 0;
        for( auto& it : dp){
            for( int i  =  0 ;i <= m ; i++ ){
                maxi = max( maxi , it[i]); 
            }
        }
        return maxi ; 
        
    }
};