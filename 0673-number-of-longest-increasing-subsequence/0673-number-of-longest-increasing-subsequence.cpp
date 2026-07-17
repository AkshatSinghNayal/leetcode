class Solution {
public:
    vector<vector<pair<int,int>>> dp;

    pair<int,int> solve(vector<int>& nums, int i, int prev) {
        int n = nums.size();

        if (i == n) return {0, 1};

        if (dp[i][prev + 1].first != -1)
            return dp[i][prev + 1];

        auto notTake = solve(nums, i + 1, prev);

        pair<int,int> take = {-1000000, 0};
        if (prev == -1 || nums[prev] < nums[i]) {
            take = solve(nums, i + 1, i);
            take.first++;
        }

        if (take.first > notTake.first)
            return dp[i][prev + 1] = take;

        if (take.first < notTake.first)
            return dp[i][prev + 1] = notTake;

        return dp[i][prev + 1] = {take.first, take.second + notTake.second};
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<pair<int,int>>(n + 1, {-1, -1}));
        return solve(nums, 0, -1).second;
    }
};