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

    void dfs(TreeNode* root , vector<TreeNode*>& ans ){
        if(!root) return ; 
        ans.push_back(root); 
        dfs(root->left , ans ); 
        dfs(root->right , ans); 
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*>ans; 
        dfs( root ,ans ); 

        TreeNode* home = root;
        queue<TreeNode*>q;
        q.push(root);
        
        int i  = 1; 
        while(!q.empty() and i < ans.size() ){
            auto node = q.front(); q.pop(); 
            node->right = ans[i++]; 
            node->left = nullptr; 
            q.push(node->right);
        }
        
    }
};