class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0, r = 0;
        int maxLen = 0; 
        int countZeros = 0;

        while (r < nums.size()) {

            if (nums[r] == 1) {
                r++;
            }
            else if (nums[r] == 0 && countZeros < k) {
                countZeros++;
                r++;
            }
            else { // nums[r] == 0 && countZeros == k
                // shrink window from left until we can include this zero
                if (nums[l] == 0) countZeros--;
                l++;
            }

            maxLen = max(maxLen, r - l); 
        }
        return maxLen; 
    }
};
