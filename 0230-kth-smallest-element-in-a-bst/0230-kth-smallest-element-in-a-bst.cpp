class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* current = root;
        int count = 0;
        
        while (current != nullptr || !s.empty()) {
            // Push all the left nodes to the stack
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            
            // Pop the top node from the stack
            current = s.top();
            s.pop();
            
            // Increment count and check if it's the kth smallest
            count++;
            if (count == k) {
                return current->val;
            }
            
            // Move to the right subtree
            current = current->right;
        }
        
        return -1;  // This line is never reached if k is valid
    }
};
