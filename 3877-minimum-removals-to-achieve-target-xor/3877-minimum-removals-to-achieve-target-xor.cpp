class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> dp;
        dp[0] = 0;  // XOR 0 with 0 elements

        for (auto num : nums) {
            unordered_map<int, int> new_dp = dp;

            for (auto &it : dp) {
                int x = it.first;
                int sz = it.second;

                int new_xor = x ^ num;

                if (new_dp.find(new_xor) != new_dp.end()) {
                    new_dp[new_xor] = max(new_dp[new_xor], sz + 1);
                } else {
                    new_dp[new_xor] = sz + 1;
                }
            }

            dp = new_dp;
        }

        if (dp.find(target) == dp.end()) return -1;

        return n - dp[target];  // removals = total - kept
    }
};