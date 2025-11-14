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

    void findNode( TreeNode* root , TreeNode*& node , int target ){

            if( !root ) return ; 
            if( root->val == target ){
                node = root ; 
                return ; 
            }

            if( root->left &&  root->val > target){
                findNode( root->left , node , target ); 
            }
            
            else{
                findNode( root->right , node , target ) ;
            }
            
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = nullptr ; 
        findNode( root , node  , val) ;
        return node ; 
    }
};