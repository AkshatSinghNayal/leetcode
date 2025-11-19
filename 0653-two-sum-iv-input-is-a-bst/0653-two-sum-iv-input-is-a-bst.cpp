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

    void helperFunction ( TreeNode* root , int k , unordered_set<int>& st , bool&found  ){
        if( !root ) return ; 

        int target = k  - root->val ; 
        if( st.find( target) != st.end()){
            found = true;
        }
        else{
            st.insert( root->val ) ; 
        }
        helperFunction( root->left , k , st , found ) ; 
        helperFunction( root->right , k , st , found) ; 

    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st ; 
        bool found = false; 
        helperFunction( root , k  , st , found ); 
       return found ; 

    }
};