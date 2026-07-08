class Solution {
public:

    int solve(string& text1, string& text2 , vector<vector<int>>&dp , int i , int j ){
        //base 
         if( i < 0 or j<0 ) return 0; 

        if( dp[i][j] != -1 ) return dp[i][j]; 

        int call = ( text1[i] == text2[j]) ? 1 + solve( text1 , text2 , dp , i-1 , j-1 ) : max( solve(text1 , text2 , dp , i , j-1) , solve(text1 , text2 , dp , i-1 , j)); 

        return dp[i][j] = call; 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size(); 
        vector<vector<int>>dp(n , vector<int>(m , -1)); 
        return solve( text1 , text2 , dp , n-1 , m-1 ); 
    }
};