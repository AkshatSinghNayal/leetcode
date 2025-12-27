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

    int solve( TreeNode* root ,int& maxi ){
        if(!root) return 0; 
        if( root->left == nullptr and root->right == nullptr) return 1 ; 
        int left = solve( root->left , maxi  ); 
        int right = solve( root->right , maxi ); 

        maxi = (maxi<left+right) ? left+right : maxi ; 


        return 1+ max( left , right); 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 1; 
        if( !root->left and !root->right) return 0 ; 
        int ans = solve( root , maxi );
        return maxi ; 
    }
};