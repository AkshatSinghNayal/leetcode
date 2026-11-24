class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int i, int inc, int n) {
        if (i >= n) return 0;
        if (dp[i][inc] != -1) return dp[i][inc];

        int last = nums[i] + inc;
        int ans = 1; // Count the current element nums[i] itself

        // Option 1: Find the next occurrence of `last` and increment it to `last + 1`
        int idx1 = lower_bound(nums.begin() + i + 1, nums.end(), last) - nums.begin();
        if (idx1 < n && nums[idx1] == last) {
            ans = max(ans, 1 + solve(nums, dp, idx1, 1, n));
        }

        // Option 2: Find the next occurrence of `last + 1` and keep it as is (`inc = 0`)
        int idx2 = lower_bound(nums.begin() + i + 1, nums.end(), last + 1) - nums.begin();
        if (idx2 < n && nums[idx2] == last + 1) {
            ans = max(ans, 1 + solve(nums, dp, idx2, 0, n));
        }

        return dp[i][inc] = ans;
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        int ans = 1;
        // The sequence can start at ANY index i
        for (int i = 0; i < n; i++) {
            ans = max({ans, solve(nums, dp, i, 0, n), solve(nums, dp, i, 1, n)});
        }
        return ans;
    }
};