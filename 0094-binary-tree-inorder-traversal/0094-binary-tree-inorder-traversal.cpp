class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;

        inorder(root->left, ans);      // Left
        ans.push_back(root->val);      // Root
        inorder(root->right, ans);     // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
