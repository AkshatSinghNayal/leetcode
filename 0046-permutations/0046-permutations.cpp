class Solution {
public:

    void solve(vector<int>& temp, vector<vector<int>>& ans, int index, int n) {
        
        if(index == n) {
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < n; i++) {
            swap(temp[i], temp[index]);

            solve(temp, ans, index + 1, n);

            swap(temp[i], temp[index]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = nums;

        solve(temp, ans, 0, temp.size());

        return ans;
    }
};
