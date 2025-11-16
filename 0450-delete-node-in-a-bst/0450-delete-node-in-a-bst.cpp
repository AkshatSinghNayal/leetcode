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
    TreeNode* deleteNode(TreeNode* Node, int key) {
        TreeNode* root= Node ; 
        if( !root ) return root; 

        if( root->val > key ){
            root->left = deleteNode(root->left , key ) ; 
        }
        else if ( root->val < key ){
            root->right = deleteNode( root->right , key ) ; 
        }
        else{   
            
            // case1: 
            // both the nodes are nullptr so we will return nullptr 
            if( !root->right && !root->left ) return nullptr ; 

            // case2 : 
            // when one node is nullptr and other one is not nullptr so we will return the not null node ; 

            if(!root->left ) return root->right ; 
            if(!root->right) return root->left ; 


            // case3:
            // when both are nodes are not-null so  we have to compare and return according to the situation 

            TreeNode* greatest = root->right ; 
            TreeNode* ans = root->left ; 
            TreeNode* smallest = root->left ; 

            while( smallest->right ){
                smallest = smallest->right; 
            }
            smallest->right= greatest ; 

            return ans ;




        }
        return Node ; 

    }
};