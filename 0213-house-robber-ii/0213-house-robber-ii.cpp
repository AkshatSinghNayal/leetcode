class Solution {
public:

    int robLinear(vector<int>& nums, int l, int r) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = l; i <= r; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;

            int cur = max(take, notTake);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // case 1: exclude last
        int case1 = robLinear(nums, 0, n - 2);

        // case 2: exclude first
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};