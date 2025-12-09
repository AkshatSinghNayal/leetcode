class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size() ; 
        if( n ==1 ) return nums[0] ; 
        vector<int> dp(n,-1); 
        dp[0] =  nums[0]; 

        for( int i = 1  ; i<n ; i++){
            int take =  nums[i] ; if( i>=2 ) take+=dp[i-2] ; 
            int notTake = dp[i-1]; 

            dp[i] = max( take,notTake ); 
        }
        return dp[n-1];
    }
};