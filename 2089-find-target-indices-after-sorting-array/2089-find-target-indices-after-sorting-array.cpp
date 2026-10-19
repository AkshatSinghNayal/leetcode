class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smallerNo = 0, largerNo = 0;

        for (int num : nums) {
            if (num < target) smallerNo++;
            else if (num > target) largerNo++;
        }

        vector<int> ans;

        for (int i = smallerNo; i < nums.size() - largerNo; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};