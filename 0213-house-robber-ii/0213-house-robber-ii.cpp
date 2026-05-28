class Solution {
public:
    
    int solve(vector<int>& nums, int idx, int prev, int end,
              vector<vector<int>>& dp) {
        
        if (idx > end) return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        // not take
        int notTake = solve(nums, idx + 1, prev, end, dp);

        // take
        int take = 0;
        if (prev == -1 || idx - prev > 1) {
            take = nums[idx] +
                   solve(nums, idx + 1, idx, end, dp);
        }

        return dp[idx][prev + 1] = max(take, notTake);
    }

    int helper(vector<int>& nums, int start, int end) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, start, -1, end, dp);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // case 1 -> exclude last
        int case1 = helper(nums, 0, n - 2);

        // case 2 -> exclude first
        int case2 = helper(nums, 1, n - 1);

        return max(case1, case2);
    }
};