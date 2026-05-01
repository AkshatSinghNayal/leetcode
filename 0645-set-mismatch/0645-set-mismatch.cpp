class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        int set_bit = xr & -xr;

        int a = 0, b = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] & set_bit) a ^= nums[i];
            else b ^= nums[i];

            if((i + 1) & set_bit) a ^= (i + 1);
            else b ^= (i + 1);
        }

        for(int x : nums) {
            if(x == a) return {a, b};
        }

        return {b, a};
    }
};