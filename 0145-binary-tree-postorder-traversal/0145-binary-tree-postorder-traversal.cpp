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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        vector<int> ans ; 
        TreeNode* curr = root ;
        TreeNode* last  = nullptr; 
        while( !st.empty() || curr!=nullptr){
            while( curr!=nullptr ){
                st.push(curr) ; 
                curr = curr->left ; 
            }
        
        curr = st.top() ; 
        if( curr->right!=nullptr && last != curr->right  ){
            curr=curr->right ; 
        }
        else{
            ans.push_back(curr->val); 
            st.pop() ; 
            last = curr; 
            curr = nullptr ; 

        }
        }
        return ans ; 
    }
};