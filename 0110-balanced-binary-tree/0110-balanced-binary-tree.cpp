class Solution {
public:
    int check(TreeNode* root) {
        if (!root) return 0;

        int left = check(root->left);
        if (left == -1) return -1; // already unbalanced

        int right = check(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1; // unbalanced at this node

        return 1 + max(left, right); // balanced, return height
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
