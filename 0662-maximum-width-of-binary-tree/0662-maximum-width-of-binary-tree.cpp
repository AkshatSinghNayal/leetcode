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
    int widthOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        if(!root->left and !root->right ) return 1; 
        queue<pair<TreeNode*,long long>>q; 
        q.push({root,0});
        long long mini = 0; 

        while(!q.empty()){
            long long left =0 , right = 0 ;
            long long size =q.size();
            mini = q.front().second;
            for(int i = 0;i<size ;i++ ){
                auto [node , idx] = q.front() ; q.pop(); 
                idx-=mini;
                if( i == 0  ){
                    left = idx; 
                }
                if(i == size-1 ){
                    right = idx;
                }

                if( node->left ) q.push({node->left , 1LL*idx*2+1}); 
                if(node->right) q.push({node->right , 1LL*idx*2+2}); 


            }
            maxi = ( right-left+1 > maxi ) ? right-left+1 : maxi; 

        }

        return maxi; 
    }
};