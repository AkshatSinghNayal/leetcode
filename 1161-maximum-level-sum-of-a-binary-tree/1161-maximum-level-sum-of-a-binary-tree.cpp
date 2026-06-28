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
        queue<TreeNode*>q; 
        q.push(root); 

        pair<long long,int>best; // sum , level
        best = {INT_MIN,INT_MIN};
        int level =0; 

        while(!q.empty()){
            ++level;
            long long total = 0; 
            int size = q.size(); 
            for(int i  = 0;i<size; i++ ){
                auto node = q.front() ; q.pop(); 
                total+=node->val;


                if(node->left) q.push(node->left); 
                if(node->right) q.push(node->right); 
            }

            if(best.first < total ){
                best ={total, level}; 
            }
        }
        // cout<<best.first << " " << best.second;
        return best.second;
    }
};