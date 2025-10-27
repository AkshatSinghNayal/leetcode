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
 void helperFunction(TreeNode* root , vector<vector<int>>& ans , int level ){
        if( root == nullptr ) return ;
        if( ans.size() == level ) {
            ans.push_back({}); 
        }
        ans[level].push_back(root->val); 
        helperFunction( root->left , ans , level+1); 
        helperFunction( root->right , ans , level +1 ); 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        helperFunction( root, ans , 0 ); 
        for( int i = 1 ; i<ans.size() ; i++){
           if(i%2 != 0){
             reverse(ans[i].begin(),ans[i].end()); 
           }
        }

        return ans ; 
    }
};