class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp,
              unordered_map<int, vector<int>>& pos,
              int i, int diff, int n) {

        if (i >= n) return 0;

        if (dp[i][diff + 500] != -1)
            return dp[i][diff + 500];

        int ans = 1;
        int target = nums[i] + diff;

        if (pos.count(target)) {
            auto& v = pos[target];

            auto it = upper_bound(v.begin(), v.end(), i);

            if (it != v.end()) {
                int idx = *it;
                ans = max(ans, 1 + solve(nums, dp, pos, idx, diff, n));
            }
        }

        return dp[i][diff + 500] = ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(1001, -1));

        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];

                ans = max(ans, 1 + solve(nums, dp, pos, j, diff, n));
            }
        }

        return ans;
    }
};