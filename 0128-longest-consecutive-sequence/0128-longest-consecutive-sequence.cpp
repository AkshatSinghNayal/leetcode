class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());  // Insert all numbers into the set
        int maxi = 0;
        
        for (const auto& num : st) {
            // Only start counting if `num - 1` is not in the set, to avoid counting the same sequence twice
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int count = 1;
                
                // Count the length of the current sequence
                while (st.find(currentNum + 1) != st.end()) {
                    count++;
                    currentNum++;
                }
                
                maxi = max(maxi, count);  // Update the maximum length
            }
        }
        
        return maxi;
    }
};
