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

    pair<int,TreeNode*> solve( TreeNode* root ){
        if( !root ) return {0, nullptr }; 

        auto [ lHeight , Llca ] = solve( root->left ); 
        auto [rHeight  , Rlca ] = solve( root->right ); 

        if( lHeight > rHeight ){
            return {lHeight+1 , Llca};
        }
        else if(lHeight<rHeight){
            return {rHeight+1 , Rlca}; 
        } 
        return { lHeight+1 , root }; 
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if( !root ) return root ; 
        auto [ height , lca ] = solve( root );
        return lca ; 
    }
};