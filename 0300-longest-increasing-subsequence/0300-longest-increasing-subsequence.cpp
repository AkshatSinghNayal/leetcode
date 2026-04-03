class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[curr][prev+1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // base case already handled: dp[n][*] = 0

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {

                int take = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                int notTake = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, notTake);
            }
        }

        // start from curr = 0, prev = -1 → shifted to 0
        return dp[0][0];
    }
};