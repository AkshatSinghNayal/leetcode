class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (auto num : nums) {
            // Update `ones` to include current number's bits that are not in `twos`
            ones = (ones ^ num) & ~twos;

            // Update `twos` to include current number's bits that are not in `ones`
            twos = (twos ^ num) & ~ones;
        }

        // `ones` contains the single number that appears only once
        return ones;
    }
};