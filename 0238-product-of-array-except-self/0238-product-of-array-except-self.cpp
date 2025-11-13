class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Special case for size 1
        if (n == 1) {
            return {0};  // No other elements to multiply with
        }
        
        // Result array to store the answer
        vector<int> result(n, 1);
        
        // Calculate prefix product
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        
        // Calculate suffix product in reverse and multiply with result
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        
        return result;
    }
};
