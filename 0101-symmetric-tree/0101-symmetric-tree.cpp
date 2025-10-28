class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val == q->val) {
            // \U0001f501 Just swapped q->left and q->right to make it mirror check
            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        return isSameTree(p, q);
    }
};
