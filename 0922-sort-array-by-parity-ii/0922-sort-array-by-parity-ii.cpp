class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0; // even index
    int odd = 1;  // odd index
    vector v(nums.size(), 0);
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            v[even] = nums[i];
            even += 2;
        } else {
            v[odd] = nums[i];
            odd += 2;
        }
    }
    return v;
    }
};