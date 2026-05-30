class Solution {
public:

    int solve( vector<int>& nums , vector<vector<int>>& dp , int i , int target ){
        //base 
        if(i<0){
            return (target == 0 ) ? 1 : 0 ;
        }
        if( dp[i][target] != -1 ) return dp[i][target]; 

        long long  take = ( target>= nums[i]) ? solve( nums , dp , i-1 , target-nums[i]) : 0 ; 
        long long notTake = solve(nums,dp , i-1 , target); 

        return dp[i][target] = take+notTake;
    }

    int findTargetSumWays(vector<int>& nums, int want) {
        int n = nums.size();
        long long total = accumulate( nums.begin() , nums.end() , 0LL ); 
        if(  (total - want) <0 or  (total - want) %2 != 0 ) return 0 ; 
        int target = ( total - want )/2; 
        vector<vector<int>>dp(n,vector<int>(target+1 , -1 )); 
       
        return solve( nums , dp , n-1 , target ) ;   
    }
};