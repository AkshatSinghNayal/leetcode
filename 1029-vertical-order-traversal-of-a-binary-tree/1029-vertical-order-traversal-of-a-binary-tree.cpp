class Solution {
public:
    void helper(TreeNode* root, int row, int col, map<int, vector<pair<int,int>>> &mp) {
        if (!root) return;
        mp[col].push_back({row, root->val});
        helper(root->left, row + 1, col - 1, mp);
        helper(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp; // col -> list of (row, val)
        helper(root, 0, 0, mp);

        vector<vector<int>> ans;
        for (auto &it : mp) {
            auto &vec = it.second;
            sort(vec.begin(), vec.end(), [](auto &a, auto &b){
                if (a.first == b.first) return a.second < b.second; // same row → sort by val
                return a.first < b.first; // otherwise sort by row
            });

            vector<int> temp;
            for (auto &p : vec) temp.push_back(p.second);
            ans.push_back(temp);
        }
        return ans;
    }
};
