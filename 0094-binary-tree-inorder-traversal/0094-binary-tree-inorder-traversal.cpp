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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ; 
        stack<TreeNode*> st ;
        
        TreeNode* curr = root;
    
        while( !st.empty() || curr!=nullptr){
            while(curr!=nullptr){
                st.push(curr);
                curr = curr->left ; 
            }
            curr = st.top(); 
            ans.push_back(curr->val); 
            st.pop();

            
            curr = curr->right;
        }
        return ans ; 
    }
};