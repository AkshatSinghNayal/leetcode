class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ; 
        vector<vector<int>>dp(n , vector<int>(n ,1e9)); 
        
        for(int i =n-1 ;i>=0 ;i-- ){
            dp[n-1][i] = triangle[n-1][i]; 
        }

        for(int i = n-2; i>=0; i--){
            for(int j=n-2 ;j>=0 ;j-- ){
                if(dp[i+1][j] ==  1e9 or dp[i+1][j+1] == 1e9 ) continue;
                int forward = dp[i+1][j]; 
                int right = dp[i+1][j+1]; 
                dp[i][j] = triangle[i][j] + min(forward , right);
            }
        }
        return dp[0][0];
    }
};