class Solution {
  public:
    
    int solve(vector<vector<int>>&dp , int i , int target , vector<int>& arr ){
        //base 
        if( i < 0 ){
            return (target == 0  ) ? 1 : 0;
        }
        
        if( dp[i][target] !=-1 ) return dp[i][target]; 
        
        int take = 0; 
        if( target >= arr[i]){
            take = solve( dp , i-1 , target-arr[i] , arr ); 
        }
        int notTake = solve( dp , i-1 , target , arr ); 
        
        
        return dp[i][target] = (take + notTake ); 
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        int n  = arr.size(); 
        int sum = accumulate(arr.begin() , arr.end() , 0); 
        if ((sum - diff) < 0 || (sum - diff) % 2 != 0) return 0;
        int target = (sum-diff)/2;
        vector<vector<int>>dp( n , vector<int>(target+1 ,-1)); 
        return solve( dp , n-1 , target , arr ); 
     
    }
};