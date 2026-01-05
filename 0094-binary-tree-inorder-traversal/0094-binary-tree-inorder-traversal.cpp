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
        stack<TreeNode*> st; 
        auto currNode = root;
        vector<int> ans; 
        if( root==nullptr ) return {};
        if( root->left == nullptr and root->right == nullptr ) return { root->val};

        while( currNode!=nullptr or !st.empty() ){
            while( currNode!=nullptr ){
                st.push(currNode); 
                currNode=currNode->left; 
            }

            currNode = st.top();
            st.pop(); 
            ans.push_back(currNode->val); 
            currNode=currNode->right; 

        }
        return ans;

    }
};