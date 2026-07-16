class Solution {
public:
    int dp[21][21][2];

    int solve(vector<int>& nums, int left, int right, int n, int p1) {
        // base
        if (left > right) return 0;
        if (dp[left][right][p1] != -1) return dp[left][right][p1];

        int win = 0;
        if (p1) {
            int takeLeft = nums[left] + solve(nums, left + 1, right, n, false);
            int takeRight =nums[right] + solve(nums, left, right - 1, n, false);

            win = max(takeLeft, takeRight);
        } else {
            int takeLeft = solve(nums, left + 1, right, n, true);
            int takeRight = solve(nums, left, right - 1, n, true);

            win = min(takeLeft, takeRight);
        }
        return dp[left][right][p1] = win;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, 0, n - 1, n, true);
        return ans * 2 >= accumulate(nums.begin(), nums.end(), 0);
    }
};