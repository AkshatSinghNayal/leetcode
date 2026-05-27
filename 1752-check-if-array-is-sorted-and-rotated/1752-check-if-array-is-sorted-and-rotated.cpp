class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int idx = min_element(nums.begin(), nums.end()) - nums.begin();

        int violations = 0;

        for (int i = idx; i < idx + n; i++) {
            if (nums[i % n] > nums[(i + 1) % n]) {
                violations++;
                if (violations > 1) return false;
            }
        }

        return true;
    }
};