class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(mp.count(nums[right]) && right - mp[nums[right]] <= k)
                return true;
            mp[nums[right]] = right;
        }
        return false;
    }
};
