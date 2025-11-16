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

    void inorder( TreeNode* root , int k  , vector<int>& ans ){

        if(!root) return ; 

        inorder( root->left , k , ans  );
        ans.push_back(root->val); 
        inorder( root->right , k , ans ); 

        

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans ; 
        inorder(root , k  , ans ) ; 
        int result=ans[k-1]; 
        return result ; 

    }
};