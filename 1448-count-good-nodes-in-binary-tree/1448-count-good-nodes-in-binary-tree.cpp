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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>>q; 
        q.push({root,root->val}); 
        int count = 1; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0 ;i<size ; i++ ){
                auto [node , val ] = q.front(); q.pop(); 

                if( node->left ){
                    int maxi = max( val , node->left->val ); 
                    if( node->left->val >= val ){
                        count++; 
                    }
                    q.push({node->left , maxi}); 
                }

                if( node->right){
                    int maxi = max( val , node->right->val ); 
                    if(node->right->val  >= val ){
                        count++;
                    }
                    q.push({node->right , maxi }); 
                }

            }
        }
        return count;
    }
};