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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q ; 
        q.push(root); 
        long long globalSum = LLONG_MIN; 
        int count =0 ; 
        int finalIndex = 1; 
        while( !q.empty() ){
            count++; 
            long long sum = 0; 
            int size = q.size(); 
            for(int i = 0 ; i< size; i++){
                auto node = q.front(); 
                q.pop(); 
                sum+=node->val; 
                if( node->left ) q.push(node->left ); 
                if(node->right ) q.push(node->right); 
            }
             
            if( sum > globalSum ){
                globalSum = sum ;  
                finalIndex = count ;
            }
        }
        return finalIndex; 
    }
};