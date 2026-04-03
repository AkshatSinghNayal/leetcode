class Solution {
public: 

    int solve(vector<int>& nums , vector<vector<int>>& dp , int curr , int prev){
        // base
        if (curr >= nums.size()) return 0;

        if( dp[curr][prev+1] != -1 ) return dp[curr][prev+1] ; 
        int take = 0 ; 
        if( prev == -1  or nums[curr] > nums[prev] ){
            take = 1 + solve(nums , dp , curr+1 , curr ); 
        }
        int notTake = solve( nums , dp , curr+1 , prev);


        return dp[curr][prev+1] = max( take , notTake) ;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=  nums.size() ; 
        vector<vector<int>>dp( n , vector<int>(n+1 ,-1)); 
        return solve( nums , dp , 0 , -1 ) ; 
    }
};