/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool helperFunction(TreeNode* &root, TreeNode* &p, TreeNode* &q , TreeNode* &node){
        if(!root) return false ; 

        bool mid = (root == q || root == p); 

      bool left =  helperFunction( root->left , p , q , node) ;
      bool right =  helperFunction( root->right , p , q , node) ;

      if( (mid && left) || (mid && right ) || ( left && right ) ){
        node = root ; 
      }

      return ( mid || left || right)  ; 

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = nullptr ; 
        helperFunction(root , p , q , node ) ; 

        return node ; 
    }
};