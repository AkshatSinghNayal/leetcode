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

    bool check ( TreeNode* root ){
        if( !root->left and !root->right ) return true; 
        return false ; 
    }

    void dfs( TreeNode* root , long long& totalSum){

        if( !root ) return ; 

        if( root->left and check( root->left )){
            totalSum+=root->left->val;
        }

        dfs( root->left , totalSum); 
        dfs( root->right , totalSum); 

    }

    int sumOfLeftLeaves(TreeNode* root) {
        long long totalSum= 0 ; 
        dfs( root , totalSum);
        return totalSum ; 
    }
};