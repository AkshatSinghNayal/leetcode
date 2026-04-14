class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size() ; 
        vector<int>dp(target+1);
        dp[0] =1; 
        
        
        for(int i = 1 ; i<=n; i++ ){
            for(int tar = target ;tar>=0; tar-- ){
                dp[tar] = dp[tar] + ((arr[i-1] <= tar) ? dp[tar - arr[i-1]] : 0); 
            }
        }
        return dp[target]; 
        
    }
};