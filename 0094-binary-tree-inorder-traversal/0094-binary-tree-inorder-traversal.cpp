class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st; 
        vector<int> ans ; 
        
        if (!root) return ans;      // FIX 1: handle null root
        st.push(root);
        auto curr = root;           // FIX 2: don't use st.top() here

        while (!st.empty()) {       // FIX 3: remove curr != nullptr
            while (curr->left) {
                st.push(curr->left);
                curr = curr->left;
            }

            bool flag = true;
            while (flag) {
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);

                if (curr->right) {
                    st.push(curr->right);
                    curr = curr->right;
                    flag = false;
                }

                if (st.empty()) break;   // FIX 4: avoid popping from empty stack
            }
        }

        return ans;
    }
};
