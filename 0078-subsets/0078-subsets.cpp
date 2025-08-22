class Solution {
public:
    void generate(int i, vector<int>& nums, vector<int>& temp,
                  vector<vector<int>>& result, int size) {

        if (i >= size) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        generate(i + 1, nums, temp, result, size);
        temp.pop_back();
        generate(i + 1, nums, temp, result, size);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> temp;
        int size = nums.size();
        generate(0, nums, temp, result, size);
        return result;
    }
};