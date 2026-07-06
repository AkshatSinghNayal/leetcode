class Solution {
public:

    bool solve(vector<int>& nums ,vector<vector<int>>& dp , int i, int target ){
        //base 
        if(target == 0 )return true;
        if( i< 0 ) return target == 0; 
        if(dp[i][target] != -1 ) return dp[i][target];

        bool take =    ( target>= nums[i]) ? solve(nums , dp , i-1 , target-nums[i]) :  false; 
        bool notTake =  solve(nums , dp , i-1  ,target ) ;
 
       return dp[i][target] = take|notTake; 
    }

    bool canPartition(vector<int>& nums) {
        int n  = nums.size(); 
        long long total = accumulate(nums.begin() , nums.end() , 0LL); 
        if( total%2 != 0 ) return 0; 
        int target  = total/2; 
        vector<vector<int>>dp(n ,vector<int>(target+1 , -1 )); 

        return solve( nums , dp , n -1 , target); 
    }
};