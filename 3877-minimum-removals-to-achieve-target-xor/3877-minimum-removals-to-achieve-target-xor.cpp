class Solution {
public:

    int solve( vector<int>& nums , int target , int i , vector<vector<int>>& dp ){
        // 
        if( i<0 ){
            if( target == 0  ) return 0; 
            else return 1e9;
        }

        if(dp[i][target] != -1 ) return dp[i][target] ; 

        return dp[i][target] = min(solve(nums ,target^nums[i] , i-1 , dp), 1+solve(nums, target , i-1 , dp )); 
    }

    int minRemovals(vector<int>& nums, int target) {
        int MAX_VAL = 1<<14 , n = nums.size();
        vector<vector<int>>dp(n , vector<int>(MAX_VAL,-1)); 
        int ans = solve( nums , target , n-1 , dp );
        return (ans>= 1e9 ) ? -1 : ans ; 
    }
};