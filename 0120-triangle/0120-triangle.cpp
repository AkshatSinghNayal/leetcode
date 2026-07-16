class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ; 
        vector<int>dp(n ,1e9); 
        
        for(int i =n-1 ;i>=0 ;i-- ){
            dp[i]= triangle[n-1][i]; 
        }

        for(int i = n-2; i>=0; i--){
            vector<int>curr(n,1e9);
            for(int j=n-2 ;j>=0 ;j-- ){
                if(dp[j] ==  1e9 or dp[j+1] == 1e9 ) continue;
                curr[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
            dp = curr;
        }
        return dp[0];
    }
};