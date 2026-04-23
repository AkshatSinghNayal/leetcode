class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows); 
        for(int i = 1; i<= numRows ; i++ ){
            dp[i-1].resize(i); 
            dp[i-1][0] = 1; 
        }
        for(int i  =1; i<numRows ; i++ ){
            int size = dp[i].size(); 
            for(int j = 1; j<size; j++  ){
                dp[i][j] = (j > 0 ? dp[i-1][j-1] : 0) +(j < dp[i-1].size() ? dp[i-1][j] : 0);
            }
        }
        return dp ; 
    }
};