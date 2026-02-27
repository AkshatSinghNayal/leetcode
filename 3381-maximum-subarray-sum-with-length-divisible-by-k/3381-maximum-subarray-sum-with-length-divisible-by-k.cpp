class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix = 0;
        long long ans = LLONG_MIN;

        unordered_map<int, long long> mp;
        mp[0] = 0;   // base case: prefix before array starts

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            int rem = (i + 1) % k;  // length remainder

            if(mp.count(rem)) {
                ans = max(ans, prefix - mp[rem]);
                mp[rem] = min(mp[rem], prefix);
            } else {
                mp[rem] = prefix;
            }
        }

        return ans;
    }
};