class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // prefix sum 0 occurs once
        
        int pre = 0;
        int count = 0;

        for (int x : nums) {
            pre += x;
            int need = pre - k;

            // if need exists, add all occurrences
            if (mp.count(need)) {
                count += mp[need];
            }

            // record prefix sum
            mp[pre]++;
        }

        return count;
    }
};
