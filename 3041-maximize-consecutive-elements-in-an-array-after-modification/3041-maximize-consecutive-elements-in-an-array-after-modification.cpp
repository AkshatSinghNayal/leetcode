class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        int total = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int inc = 0; inc <= 1; inc++) {

                int last = nums[i] + inc;
                int ans = 0;

                int idx = lower_bound(nums.begin() + i + 1, nums.end(), last) - nums.begin();

                if (idx < n && nums[idx] == last) {
                    ans = max(ans, 1 + dp[idx][1]);
                }
                else if (idx < n && nums[idx] == last + 1) { 
                    ans = max(ans, 1 + dp[idx][0]);
                }

                dp[i][inc] = ans;
            }

            total = max({total, 1 + dp[i][0], 1 + dp[i][1]});
        }

        return total;
    }
};