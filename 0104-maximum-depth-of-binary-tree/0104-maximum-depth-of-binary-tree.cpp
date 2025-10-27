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

    int helper( TreeNode* root , int level ){
        if( root == nullptr ){
            return level-1 ; 
        }
       int l1 = helper( root->left , level + 1 ); 
       int l2 = helper( root->right , level +1 ) ;

       return max(l1,l2);

        
    }

    int maxDepth(TreeNode* root) {
    return  helper(root , 1); 
       
    }
};