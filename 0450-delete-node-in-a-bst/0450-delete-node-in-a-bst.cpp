class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Found the node to delete

            // Case 1: no children
            if (!root->left && !root->right) {
                return nullptr;
            }

            // Case 2: one child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: two children
            // find inorder successor (smallest in right subtree)
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }

            // replace root value with successor value
            root->val = successor->val;

            // delete the successor
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};
