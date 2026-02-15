class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<long long> dp(n);
        
        // Base case
        dp[0] = nums[0];
        
        // Handle i = 1 separately
        dp[1] = max((long long)nums[1], dp[0]);
        if (colors[1] != colors[0]) {
            dp[1] = max(dp[1], (long long)nums[1] + nums[0]);
        }
        
        for (int i = 2; i < n; i++) {
            // Skip current
            dp[i] = dp[i - 1];
            
            // Take non-adjacent
            dp[i] = max(dp[i], (long long)nums[i] + dp[i - 2]);
            
            // Take adjacent if colors differ
            if (colors[i] != colors[i - 1]) {
                dp[i] = max(dp[i], (long long)nums[i] + dp[i - 1]);
            }
        }
        
        return dp[n - 1];
    }
};
