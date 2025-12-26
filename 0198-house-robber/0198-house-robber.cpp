class Solution {
public:

    int solve( vector<int>& nums , vector<int>& dp , int i ){
        if( i<0 ) return 0; 
        if( i == 0 ) return nums[i]; 

        if( dp[i] != -1 ) return dp[i] ; 

        int take = nums[i]+solve( nums , dp , i-2 ); 
        int notTake = solve( nums , dp , i-1 ); 

        return dp[i] = max( take , notTake ) ; 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n ,-1);
        return solve( nums , dp , n-1  ); 
    }
};