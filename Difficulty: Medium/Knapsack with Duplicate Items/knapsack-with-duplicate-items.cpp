class Solution {
  public:
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1 , 0)); 
        for(int i  =0 ; i<= capacity ; i++){
            dp[0][i] = ( i>= wt[0] ) ? (i/wt[0])*val[0] : 0; 
        } 
        
        for(int i  = 1  ;i < n ; i++ ){
            for(int j = 0 ; j<= capacity ; j++ ){
                int take = 0; 
        if(j>= wt[i]){
            take = val[i]+dp[i][j - wt[i]]; 
        }
        int notTake = dp[i-1][j] ; 
            
        
         dp[i][j] = max(take,notTake);
            }
        }
        return dp[n-1][capacity]; 
    }
};