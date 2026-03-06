class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {

        long long target = accumulate(arr.begin(), arr.end(), 0);

        if (target < diff || (target + diff) % 2 != 0)
            return 0;

        int s1 = (target + diff) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        if (arr[0] <= target) dp[arr[0]] += 1;

        for (int i = 1; i < arr.size(); i++) {
            for (int tar = target; tar >= 1 && arr[i] <= tar; tar--) {
                dp[tar] += dp[tar - arr[i]];
            }
        }

        return dp[s1];
    }
};
