class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pro = 1;

        // Left to right
        for (int i = 0; i < nums.size(); i++) {
            pro *= nums[i];
            ans = max(ans, pro);
            if (pro == 0) pro = 1; // reset after zero
        }

        pro = 1;
        // Right to left
        for (int i = nums.size()-1; i >= 0; i--) {
            pro *= nums[i];
            ans = max(ans, pro);
            if (pro == 0) pro = 1; // reset after zero
        }

        return ans;
    }
};
