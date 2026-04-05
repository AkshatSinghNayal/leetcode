class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size() ;
        vector<vector<int>>dp(n+1,vector<int>(n+1 ,0 )); 

        // for(int i  = 0 ; i<=n; i++ ){
        //     dp[n][i] = 0; 
        // } base case see memoization for clear vision  

        for(int currIdx = n-1 ;currIdx>=0 ;currIdx-- ){
            for(int prevIdx = currIdx-1 ; prevIdx>=-1 ; prevIdx-- ){
                int take = 0; 
                if( prevIdx == -1 || nums[currIdx] > nums[prevIdx]  ){
                    take = 1 + dp[currIdx+1][currIdx+1]; 
                }
                dp[currIdx][prevIdx+1] = max( take , dp[currIdx+1][prevIdx+1]); 
            }
        }
        return dp[0][0]; 
    }
};