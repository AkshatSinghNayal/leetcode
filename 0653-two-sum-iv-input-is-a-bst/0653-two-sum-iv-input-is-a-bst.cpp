class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (curr || !s.empty()) {
            while (curr) { // Go to the leftmost node
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            
            // Check if the complement exists
            if (st.find(k - curr->val) != st.end()) {
                return true;
            }
            
            // Insert current node value into the set
            st.insert(curr->val);
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        return false;
    }
};
