class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size() ; 
        vector<vector<int>>dp( n , vector<int>(target+1 , 0)); 
        dp[0][0] =1; 
        if( arr[0]<= target ) dp[0][arr[0]]++;
        
        for(int i=1 ; i< n ;i++ ){
            for(int tar  = target ; tar>= 0 ; tar-- ){
                dp[i][tar] = dp[i-1][tar]+(( arr[i]<= tar ) ? dp[i-1][tar - arr[i]] :  0); 
            }
        }
        return dp[n-1][target] ;
    }
};