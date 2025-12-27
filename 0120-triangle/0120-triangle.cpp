class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();

        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(triangle[i].size(), 1e8);
        }
        dp[0][0] = triangle[0][0]; 

        for( int i  =1 ; i< n ; i++){
            for(int j  = 0 ; j<triangle[i].size(); j++){
                int up = (j< triangle[i].size()-1 ) ? dp[i-1][j] : 1e8; 
                int left = ( j-1 >=0 ) ? dp[i-1][j-1] : 1e8; 

                dp[i][j]= triangle[i][j]+min(up,left);
            }
        }
        int mini = INT_MAX; 
        for( int i  = 0;  i<dp[n-1].size() ; i++){
            mini = min ( mini , dp[n-1][i]); 
        }
        return mini; 
    }
};