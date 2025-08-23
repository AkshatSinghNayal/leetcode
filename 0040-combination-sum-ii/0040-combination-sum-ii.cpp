class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, vector<vector<int>>& ans,
                               vector<int>& temp, int target, int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;  // ✅ stop here
        }
        if (target < 0) return;   // ✅ pruning
        if (index >= candidates.size()) return;

        for (int i = index; i < candidates.size(); i++) {
            // skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            temp.push_back(candidates[i]);
            combinationSum2Helper(candidates, ans, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // ✅ required for duplicate skip
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum2Helper(candidates, ans, temp, target, 0);
        return ans;
    }
};
