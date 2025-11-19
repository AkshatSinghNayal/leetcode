/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int value1= p->val , value2 = q->val ; 
        if(!root) return root ; 
        if( root->val == value1 || root->val==value2  ) return root ; 
        else if( root->val> value1 && root->val > value2 ) {
        return lowestCommonAncestor( root->left , p , q ) ; 
        }
        else if( root->val < value1 && root->val<value2 ){
         return   lowestCommonAncestor( root->right , p , q) ; 
        }
        
        return root ;
    

    }
};