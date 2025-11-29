/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helperFunction(TreeNode* root, int& maxi) {
        if (root == nullptr)
            return 0;

        int left = helperFunction(root->left, maxi);
        if (left <= 0)
            left = 0;
        int right = helperFunction(root->right, maxi);
        if (right <= 0)
            right = 0;

        maxi = max(maxi, left + right + root->val);
        // if (maxi < 0)
        //     maxi = 0;

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helperFunction(root, maxi);
        return maxi;
    }
};