class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); 
        int m = text2.size(); 
        vector<int> prev(m+1 ,0 ) , curr(m+1 , 0 );

        for( int i = 1; i<=n ; i++ ){
            for( int j = 1; j<=m ; j++ ){
                curr[j] = ( text1[i-1] == text2[j-1]) ? 1+prev[j-1] : max( prev[j] , curr[j-1]);
            }
            prev = curr ; 
        }

        return prev[m]; 
        
    }
};