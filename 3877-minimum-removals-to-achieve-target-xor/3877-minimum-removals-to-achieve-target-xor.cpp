class Solution {
public:

    int solve(vector<int>& nums , vector<vector<int>>& dp , int target , int i ){
        if( i < 0 ){
            if( target == 0 ){
                return 0;
            }
            return 1e9;
        }

        if(dp[i][target] != -1 ) return dp[i][target]; 

        int take = solve( nums , dp , target^nums[i] , i-1 ); 
        int notTake = 1+ solve( nums ,dp, target , i-1); 

        return dp[i][target] = min(take , notTake);

    }

    int minRemovals(vector<int>& nums, int target) {
        int n  = nums.size(); 
        int MAX_XOR = 1 << 14; // 16384 ->> 2^x 
        vector<vector<int>> dp(n, vector<int>(MAX_XOR, -1));
        int ans = solve( nums , dp , target , n-1);

        return ( ans >= 1e9 ) ? -1 : ans; 
    }
};