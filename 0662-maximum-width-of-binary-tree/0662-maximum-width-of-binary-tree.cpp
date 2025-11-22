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
        queue<pair< TreeNode* , int>> q; 
        if( root == nullptr ) return 0 ;
        int maxi = INT_MIN ;
        q.push({ root , 0 }) ;

        while( !q.empty()){
            int size = q.size() ;
                maxi = max(maxi , q.back().second - q.front().second+1);
                int left= q.front().second;
            for( int i  = 0 ;i<size ; i++){
                
                auto node = q.front() ;
                int initial = node.second-left ;
                q.pop() ;
                
                if( node.first->left ) q.push( {node.first->left , initial*2+1 }); 
                if( node.first->right) q.push({node.first->right , initial*2+2});
                
            }
        }
        return maxi;

    }
};