class Solution {
  public:
    
    bool solve(vector<int>& arr, int sum , vector<vector<int>>&dp , int i ){
        //base
        if(i < 0 ){
            return sum == 0 ;
        }
            
        if( dp[i][sum]!=-1 ) return  dp[i][sum];
        bool take = false;
        if( arr[i] <= sum ){
            take = solve(arr , sum-arr[i] , dp , i-1 );
        }
        bool notTake = solve( arr , sum , dp , i-1 );
        
        
        return dp[i][sum] = (take | notTake);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n  = arr.size(); 
        vector<vector<int>>dp(n,vector<int>(sum+1 , -1)); 
        return solve( arr , sum , dp  , n-1 );
    }
};