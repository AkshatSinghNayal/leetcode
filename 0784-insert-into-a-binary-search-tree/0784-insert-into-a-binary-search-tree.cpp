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
    TreeNode* insertIntoBST(TreeNode* root1, int val) {
        TreeNode* root = root1 ;
        TreeNode* newNode = new TreeNode(val); 
        if( !root1 ){
            return newNode;
        }
        while( root ){
            if( root->val>val){
                if( root->left == nullptr ){
                    root->left = newNode ; 
                    break; 
                }
                root = root->left;
            }
            else{
                if( root->right == nullptr ){
                    root->right = newNode ; 
                    break; 
                }
                root  = root->right ; 
            }
        }
        return root1 ; 
    }
};