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
        int maxi = INT_MIN;
    int helper(TreeNode* root) {
        if (root == nullptr)
            return 0; // base case: empty tree → depth = 0

        int left = helper(root->left);
        int right = helper(root->right);

        return 1 + max(left, right); // include current node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if( root == nullptr) return 0 ;
        int left = helper(root->left);
        int right = helper(root->right);

        maxi = max(maxi, left + right);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        

        return maxi;
    }
};