class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int len = INT_MAX;
        int left = 0, right = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        long long sum = 0;
       

        while (right < n) {
            if (mp[nums[right]] == 0) {
                sum += nums[right];
            }
            mp[nums[right]]++;

            while (sum >= k) {
                len = min(len, right - left + 1);
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    sum -= nums[left];
                }
                left++;
            }
            right++;
        }
        return len == INT_MAX ? -1 : len;
    }
};
