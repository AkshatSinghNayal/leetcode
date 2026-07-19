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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root); 


        while(!q.empty()){
            int size = q.size(); 
            for(int i  = 0;i<size ;i++ ){
                auto node = q.front() ; q.pop(); 
                auto left=node->left; 
                auto right = node->right;
                if(left) q.push(left); 
                if(right) q.push(right); 
                node->left = right; 
                node->right = left; 
            }
        }
        return root; 
    }
};