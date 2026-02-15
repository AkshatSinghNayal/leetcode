// User function template for C++
class Solution {
  public:
    
    int solve(vector<int>& arr , vector<int>& dp , int n ){
        // 
        if( n< 0 ) return 0;
        if( n == 0 ) return arr[n]; 
        
        if( dp[n] != -1 ) return dp[n]; 
        
        int take =  arr[n]+solve(arr, dp , n-2)  ; 
        int notTake = solve(arr , dp , n-1); 
        
        return dp[n] = max( take , notTake);
    }
  
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n , -1); 
        
        return solve( arr , dp , n-1); 
        
    }
};