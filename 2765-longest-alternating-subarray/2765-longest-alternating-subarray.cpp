class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i + 1] - nums[i] != 1)
                continue;

            int len = 2;
            ans = max(ans, len);

            for (int j = i + 2; j < n; j++) {

                int expected = (j - i) % 2 ? 1 : 0;

                if (nums[j] == nums[i] + expected) {
                    len++;
                    ans = max(ans, len);
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};