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

    int solve( TreeNode* root , int& maxi ){

        if( !root ){
            return 0; 
        }

        int left = solve( root->left , maxi ) ; 
        int right = solve( root->right , maxi ) ;

        if( left<=0 && right<=0  ){
            maxi = max( maxi , root->val) ;
        }
        else{
           if( left > 0 && right< 0 ){
             maxi = max( maxi , root->val+ left ) ; 
           }
           else if (right>0 && left< 0 ){
            maxi = max(maxi , root->val +right) ; 
           }
           else{
            maxi = max(maxi , root->val+left+right) ; 
           }
        }


        if( left < 0 and right< 0  ){
            return root->val ; 
        }
        return root->val + max( left , right) ; 
    }

    int maxPathSum(TreeNode* root) {
          if( root->left == nullptr && root->right == nullptr) {
            return root->val ; 
        }

        int maxi = INT_MIN ;
        solve( root ,maxi ) ; return maxi ; 

    }
};