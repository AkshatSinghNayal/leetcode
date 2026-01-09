class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // Update the result by shifting left and adding the current number (binary digit)
            result = ((result << 1) | nums[i])%5;
            
            // Check if the current result is divisible by 5
            ans.push_back(result   == 0);
        }
        
        return ans;
    }
};



// Why does result * 2 + 1 work?

// Because binary is base-2.

// Rule for any number system

// If a number is written in base B, then adding a new digit d means:

// new number
// =
// (
// old number
// ×
// 𝐵
// )
// +
// 𝑑
// new number=(old number×B)+d
// Decimal example (base-10) — obvious case

// Number: 47

// Add digit 3 → 473