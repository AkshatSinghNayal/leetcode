class Solution {
public:

    int solve(vector<vector<int>>& jobs, vector<int>& dp, int i) {
        if (i >= jobs.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int next = lower_bound( jobs.begin() + i + 1, jobs.end(),vector<int>{jobs[i][1], 0, 0}) - jobs.begin();

        int take = jobs[i][2] + solve(jobs, dp, next);

        int notTake = solve(jobs, dp, i + 1);

        return dp[i] = max(take, notTake);
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        return solve(jobs, dp, 0);
    }
};