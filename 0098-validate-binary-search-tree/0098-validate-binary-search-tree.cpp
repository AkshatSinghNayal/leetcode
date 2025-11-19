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

    bool isValid( TreeNode* root , TreeNode* mini , TreeNode* maxi ){
        if( !root ) return true ; 
        if( mini != nullptr && root->val <= mini->val ) return false ; 
        if(maxi !=nullptr && root->val>= maxi->val ) return false ; 

        return isValid( root->left , mini , root) && isValid(root->right , root , maxi ) ; 
    }

    bool isValidBST(TreeNode* root) {
       return  isValid( root , nullptr , nullptr )  ; 
    }
};