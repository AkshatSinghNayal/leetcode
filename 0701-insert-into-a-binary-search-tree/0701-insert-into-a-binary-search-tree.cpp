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

    void dfs(  TreeNode*& root , int val ){
        
        if(!root->left and !root->right){
            if( root->val > val ){
                root->left = new TreeNode(val);
                return ; 
            }
            else{
                root->right = new TreeNode(val);
                return; 
            }
        }

        if( root->val > val ){
            if(!root->left ){
                 root->left = new TreeNode(val);
            return; 
            }
            dfs(root->left ,val);  
        }   
        else{
            if(!root->right){
                 root->right = new TreeNode(val);
            return ;
            }
            dfs(root->right , val ); 
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* home = root;
        if(!root) return new TreeNode(val);
        dfs(root,val);
        return home;
    }
};