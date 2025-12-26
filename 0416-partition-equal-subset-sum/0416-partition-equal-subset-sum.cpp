class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate( nums.begin(),nums.end(),0);
        if( sum%2 != 0 ) return false; 
        long long target = sum/2; 

        int n = nums.size();
        
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;  
        }
        
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int tar = 1; tar <= target; tar++) {
                bool notTake = dp[i-1][tar]; 
                bool take = false;
                
                if (nums[i] <= tar) {
                    take = dp[i-1][tar - nums[i]];  
                }

                dp[i][tar] = take || notTake;  
            }
        }

        return dp[n-1][target];
    }
};