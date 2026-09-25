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

    unordered_map<TreeNode*,int>dp;

    int solve(TreeNode* root ){
        if(!root) return 0; 

        if(dp.count(root) ) return dp[root]; 

        int take = root->val ; 
        if( root->left ){
            take +=(solve(root->left->left) +solve(root->left->right));
        }
        if( root->right ){
            take+=(solve(root->right->right) + solve(root->right->left));
        }
        

        int notTake = solve(root->left)+solve(root->right);

        return dp[root] = max( take , notTake ); 
    }

    int rob(TreeNode* root) {
        return solve(root);
    }
};