
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        vector<int> count(n, 0);
        vector<int> last(101, -1);

        int total = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            // Increase distinct count for affected subarrays
            for (int j = p + 1; j <= i; j++) {
                count[j]++;
            }

            // Calculate squared distinct counts
            // of all subarrays ending at i
            for (int j = 0; j <= i; j++) {
                total += count[j] * count[j];
            }

            last[nums[i]] = i;
        }

        return total;
    }
};
