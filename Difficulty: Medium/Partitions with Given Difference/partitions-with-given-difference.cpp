class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        const int MOD = 1e9 + 7;

        long long total = accumulate(arr.begin(), arr.end(), 0LL);

        // Feasibility checks
        if (total < diff || (total - diff) % 2 != 0)
            return 0;

        int target = (total - diff) / 2;

        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int tar = target; tar >= num; tar--) {
                dp[tar] = (dp[tar] + dp[tar - num]) % MOD;
            }
        }

        return dp[target];
    }
};
