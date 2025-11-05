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
        int maxi = LLONG_MIN ; 
        queue<pair<TreeNode* , int  >> q ;
        q.push({root , 0}); 
        while(!q.empty()){
            int size = q.size();
            maxi = max(maxi , ( (q.back().second- q.front().second)+1 ) ) ;
            for( int i = 0 ; i<size  ;i++){
                auto node = q.front(); 
                long long int temp = node.second; 
                q.pop(); 

                if( node.first->left ) q.push({node.first->left , 2*temp+1});
                if( node.first->right) q.push({node.first->right , 2*temp+2});



            }
        }
        return maxi ; 
    }
};