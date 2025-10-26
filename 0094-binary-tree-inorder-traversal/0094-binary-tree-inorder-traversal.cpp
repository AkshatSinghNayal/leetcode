class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != nullptr || !st.empty()) {
            // Go as left as possible
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process the node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // Go to right subtree
            curr = curr->right;
        }

        return ans;
    }
};
