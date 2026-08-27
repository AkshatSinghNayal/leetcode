class Solution {
public:

    void solve(vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& ans, int n, int index) {

        ans.push_back(temp);

        for (int i = index; i < n; i++) {

            // Skip duplicate choices at the same recursion level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            solve(nums, temp, ans, n, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, temp, ans, nums.size(), 0);

        return ans;
    }
};
