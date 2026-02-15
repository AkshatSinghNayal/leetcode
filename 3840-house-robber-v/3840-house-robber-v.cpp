class Solution {
public:

    long long solve(int i, int taken,vector<int>& nums,vector<int>& colors,vector<vector<long long>>& dp) {

        if(i < 0) return 0;

        if(dp[i][taken] != -1)
            return dp[i][taken];

        long long ans = 0;

        if(taken == 0) {
            // Not taking current
            ans = max(
                solve(i-1, 0, nums, colors, dp),
                solve(i-1, 1, nums, colors, dp)
            );
        }
        else {
            // Taking current
            long long val = nums[i];

            // Case 1: previous not taken
            ans = solve(i-1, 0, nums, colors, dp) + val;

            // Case 2: previous taken AND colors differ
            if(i-1 >= 0 && colors[i-1] != colors[i]) {
                ans = max(ans,solve(i-1, 1, nums, colors, dp) + val);
            }
        }

        return dp[i][taken] = ans;
    }

    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();

        vector<vector<long long>> dp(n,vector<long long>(2, -1));

        return max(solve(n-1, 0, nums, colors, dp),solve(n-1, 1, nums, colors, dp));
    }
};