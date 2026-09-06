class Solution {
public:
    // int solve( string& s , string& t , int i , int j  , int n  , int m ){
    //     //base 
    //     if(j == m ) return 1; 
    //     if( i  == n ){
    //         return ( j == m ) ? 1 : 0;
    //     }

    //     if( dp[i][j] != -1 ) return dp[i][j]; 

    //     int take = ( s[i] == t[j] ) ? solve(s , t , i+1 , j+1 , n,  m  ) : 0;

    //     int notTake = solve( s, t , i+1  ,j , n ,  m );

    //     return dp[i][j] = take+notTake;
    // }


    int numDistinct(string s, string t) {
       int n =  s.size() , m = t.size(); 
       vector<vector<int>>dp(n+1 , vector<int>(m+1, 0));
        
        for(int i = 0 ;i<=n ;i++ ){
            dp[i][m] = 1;
        }

        for(int i = n-1 ; i>=0 ;i--){
            for(int j = m-1; j>=0; j-- ){

                long long  take = ( s[i] == t[j] ) ? dp[i+1][j+1]  : 0;
                long long  notTake = dp[i+1][j];

                dp[i][j] = take+notTake;

            }
        }
        return dp[0][0]; 
    }
};