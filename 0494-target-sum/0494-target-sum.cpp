class Solution {
public:

    int solve(vector<int>& nums ,vector<vector<int>>&dp , int i , int target , int offset){
        //base
        if(target > offset or target< -offset ) return 0; 

        if( i<0 ) return target == 0 ;

        if(dp[i][target+offset] != -1 ) return dp[i][target+offset];

        int add = ( target+nums[i]<= offset) ? solve( nums , dp , i-1 , target+nums[i] , offset) : 0; 
        int sub = solve(nums , dp , i-1 , target-nums[i] , offset ); 

        return dp[i][target+offset] = add+sub; 
    }

    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  = nums.size(); 
        int total = accumulate(nums.begin(), nums.end() , 0 ) ;
        if(target > total or target< -total ) return 0; 
        int offset = total ;
        vector<vector<int>>dp(n , vector<int>(2*total+1 , -1 )); 
        return solve(nums, dp , n-1 , target , offset ); 
    }
};