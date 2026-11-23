class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp,
              int i, int inc, int n) {

        if (i >= n) return 0;

        if (dp[i][inc] != -1)
            return dp[i][inc];

        int last = nums[i] + inc;
        int take = 1;

        // Next element without incrementing
        int j = lower_bound(nums.begin() + i + 1,nums.end(), last + 1) - nums.begin();

        if (j < n && nums[j] == last + 1) take = max(take, 1 + solve(nums, dp, j, 0, n));

        // Next element after incrementing
        j = lower_bound(nums.begin() + i + 1, nums.end(), last) - nums.begin();

        if (j < n && nums[j] == last) take = max(take, 1 + solve(nums, dp, j, 1, n));

        return dp[i][inc] = take;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(nums, dp, i, 0, n));
            ans = max(ans, solve(nums, dp, i, 1, n));
        }

        return ans;
    }
};