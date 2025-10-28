/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root , int &maxi ) {
        if (root == nullptr)
            return 0; // base case: empty tree → depth = 0

        int left = helper(root->left , maxi);
        int right = helper(root->right , maxi );

        maxi = max(maxi , left+right);

        return 1 + max(left, right); // include current node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
         helper( root ,maxi );

         return maxi ; 

        

        
    }
};