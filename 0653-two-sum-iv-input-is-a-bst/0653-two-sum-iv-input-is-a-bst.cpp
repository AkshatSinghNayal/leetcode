class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        // Two stacks for iterative in-order and reverse in-order traversal
        stack<TreeNode*> inorderStack, reverseInorderStack;
        TreeNode* inorderNode = root;
        TreeNode* reverseInorderNode = root;
        
        // Initialize the in-order traversal (left to right)
        while (inorderNode) {
            inorderStack.push(inorderNode);
            inorderNode = inorderNode->left;
        }

        // Initialize the reverse in-order traversal (right to left)
        while (reverseInorderNode) {
            reverseInorderStack.push(reverseInorderNode);
            reverseInorderNode = reverseInorderNode->right;
        }

        // Two-pointer technique: one for in-order, one for reverse in-order
        while (!inorderStack.empty() && !reverseInorderStack.empty()) {
            TreeNode* leftNode = inorderStack.top();
            TreeNode* rightNode = reverseInorderStack.top();
            
            // If we find the target sum
            if (leftNode != rightNode && leftNode->val + rightNode->val == k) {
                return true;
            }
            
            // If the sum is less than k, move the in-order pointer forward (next larger element)
            if (leftNode->val + rightNode->val < k) {
                inorderStack.pop();
                TreeNode* node = leftNode->right;
                while (node) {
                    inorderStack.push(node);
                    node = node->left;
                }
            } 
            // If the sum is greater than k, move the reverse in-order pointer backward (next smaller element)
            else {
                reverseInorderStack.pop();
                TreeNode* node = rightNode->left;
                while (node) {
                    reverseInorderStack.push(node);
                    node = node->right;
                }
            }
        }
        
        return false;
    }
};
