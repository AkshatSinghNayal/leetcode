class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long sum = 0;
        for (auto& it : nums) {
            sum = (sum + it) % p;
        }
        if (sum == 0)
            return 0;
        int target = sum;
        sum = 0;
        int mini = n;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int MOD = (sum % p);
            int need = (MOD - target + p) % p;
            if (mp.count(need)) {
                mini = min(mini, i - mp[need]);
            }

            mp[MOD] = i;
        }

        return (mini == n) ? -1 : mini;
    }
};