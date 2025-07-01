class Solution {
public:
    bool search(vector<int>& nums, int target) {
        set<int> s(nums.begin(), nums.end());  // convert vector to set
        return s.find(target) != s.end();      // check if target exists
    }
};