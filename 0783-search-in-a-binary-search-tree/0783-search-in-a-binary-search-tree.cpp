/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root ; 
        queue<TreeNode*> q ; 
        q.push(root); 
        TreeNode* node = nullptr; 
        while(!q.empty()){
             node = q.front();
            q.pop() ;
            
            if( node->val == val ) {
                return node ; 
            }

            if(node->left) q.push(node->left); 
            if( node->right) q.push(node->right);
        }
        return nullptr ; 
    }
};