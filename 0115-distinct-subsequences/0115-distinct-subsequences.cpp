class Solution {
public:
    int dp[1001][1001]; 


    int solve( string& s , string& t , int i , int j  , int n  , int m ){
        //base 
        if(j == m ) return 1; 
        if( i  == n ){
            return ( j == m ) ? 1 : 0;
        }

        if( dp[i][j] != -1 ) return dp[i][j]; 

        int take = ( s[i] == t[j] ) ? solve(s , t , i+1 , j+1 , n,  m  ) : 0;

        int notTake = solve( s, t , i+1  ,j , n ,  m );

        return dp[i][j] = take+notTake;
    }


    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve( s , t ,  0 , 0 , s.size() , t.size()); 
    }
};