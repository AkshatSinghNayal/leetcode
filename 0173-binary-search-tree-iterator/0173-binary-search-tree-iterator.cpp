class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> stk;

    BSTIterator(TreeNode* root) {
        this->root = root;
    }

    int next() {
        // Go as far left as possible
        while (root) {
            stk.push(root);
            root = root->left;
        }

        // Top of stack is the next smallest element
        root = stk.top();
        stk.pop();

        int val = root->val;

        // Now process the right subtree next
        root = root->right;

        return val;
    }

    bool hasNext() {
        return root != nullptr || !stk.empty();
    }
};