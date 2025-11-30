class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums)
            total = (total + x) % p;

        // If already divisible, nothing to remove
        if (total == 0) return 0;

        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1;   // To allow subarray starting at index 0

        long long prefix = 0;
        int n = nums.size();
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;

            // We want prefix[j] such that (prefix[i] - prefix[j]) % p == total
            long long need = (prefix - total + p) % p;

            if (lastIndex.count(need)) {
                ans = min(ans, i - lastIndex[need]);
            }

            // Save / update prefix modulo index
            lastIndex[prefix] = i;
        }

        return ans == n + 1 ? -1 : ans;
    }
};
