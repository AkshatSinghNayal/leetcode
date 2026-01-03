class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left = 0;
        int n = nums.size();
        long long sum = 0;
        int length = INT_MAX;
        
        for(int right = 0; right < n; right++) {
            if(mp[nums[right]] == 0) {
                sum += nums[right];
            }
            mp[nums[right]]++;
            
            while(sum >= k) {
                length = min(length, right - left + 1);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    sum -= nums[left];
                }
                left++;
            }
        }
        
        return (length == INT_MAX) ? -1 : length;
    }
};