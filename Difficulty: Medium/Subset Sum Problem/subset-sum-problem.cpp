class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
         vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int x : arr) {
            for (int t = target; t >= x; t--) {
                dp[t] = dp[t] || dp[t - x];
                if( dp[target]) return true;
            }
        }
        return false;
    }
};
