class Solution {
public:
    int count = 0;
    int result = 0;
    
    void inorder(TreeNode* root, int k) {
        if (!root) return;
        
        inorder(root->left, k);  // Visit left subtree
        
        // Increment the count and check if we reached the kth smallest element
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        
        inorder(root->right, k);  // Visit right subtree
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
