class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Update the result by shifting left and adding the current number (binary digit)
            result = ((result << 1) + nums[i])%5;
            
            // Check if the current result is divisible by 5
            ans.emplace_back(result == 0 );
        }
        
        return ans;
    }
};
