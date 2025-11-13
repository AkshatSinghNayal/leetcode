class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_index = -1;
        int sum = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && zero_index > -1) {
                return std::vector<int>(nums.size(), 0);
            }
            if (nums[i] == 0) {
                zero_index = i;
            } else {
                sum = sum * nums[i];
            }
        }
        std::vector<int> res(nums.size(), 0);
        if (zero_index > -1) {
            res[zero_index] = sum;
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            res[i] = sum / nums[i];
        }
        return res;
    }
};