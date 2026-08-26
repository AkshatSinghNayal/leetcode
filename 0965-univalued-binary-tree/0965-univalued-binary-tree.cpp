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

    bool solve( TreeNode* root ){
        if( !root ) return true; 

        bool left = true , right = true; 
        if( root->left ){
        left = ( root->left->val  == root->val ) ? solve( root->left ) : false; 
        }
        if( root->right ){
        right = ( root->right->val == root->val ) ? solve(root->right) : false; 
        }

        return left&&right; 
        
    }

    bool isUnivalTree(TreeNode* root) {
        return solve( root ); 
    }
};