class Solution {
public:

    int solve( vector<int>&nums , vector<vector<int>>&dp, int i , int inc , int n){
        if( i >=n ) return 0; 
        if(dp[i][inc] != -1 ) return dp[i][inc]; 

       
        int last = nums[i]+inc;
        int ans = 0; 

        int idx = lower_bound(nums.begin()+i+1, nums.end() , last ) - nums.begin();

        if( idx >=n ) return 0;

        if( last+1 == nums[idx] ){
            ans = max( ans , 1+solve( nums , dp , idx , 0 , n));
        }
        else if( last == nums[idx] ){
            ans = max( ans , 1+solve(nums,dp,idx,1 , n )); 
        }
        return dp[i][inc] =   ans;
    }

    int maxSelectedElements(vector<int>& nums) {
        int ans = INT_MIN;
        sort(nums.begin() , nums.end()); 
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2, -1)); 
        for(int i = 0 ;i< n ;i++ ){
            ans = max( {ans , 1+solve(nums , dp , i , 0 , n) , 1+solve(nums, dp, i , 1, n )});
        }
        return ans;
    }
};