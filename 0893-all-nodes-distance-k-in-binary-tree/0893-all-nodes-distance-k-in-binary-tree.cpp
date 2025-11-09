/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

   void buildMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, TreeNode* parent) {
    if (!root) return;
    
    mp[root] = parent;  // Map current node to its parent
    
    // Pass the current root as the parent for the children
    buildMap(root->left, mp, root);  // Left child
    buildMap(root->right, mp, root); // Right child
}


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* parent = nullptr ; 
        unordered_map<TreeNode* , TreeNode*> mp ;
        buildMap( root , mp , parent ); 
        queue<TreeNode*> q ; 
        set<int> st ; 
        int level = 0;

        q.push(target); 
        while(!q.empty()){
             if(level == k ) break; 
            int size = q.size() ; 
            for( int i = 0; i<size ; i++){
                
                TreeNode* node= q.front();
                q.pop();
                st.insert(node->val); 

                if( node->left !=nullptr && st.find(node->left->val)==st.end()){
                    q.push(node->left);
                    st.insert(node->left->val); 
                } 
                if(node->right != nullptr  && st.find(node->right->val)==st.end()){
                     q.push(node->right);
                     st.insert(node->right->val);
                }
                if(mp[node] !=nullptr && st.find(mp[node]->val) ==st.end()) {
                    q.push(mp[node]); 
                    st.insert(mp[node]->val); 
                }

            }
                level++; 
            
        }
        vector<int> ans ; 
       
       while(!q.empty()){
            ans.push_back(q.front()->val); 
            q.pop();
       }
            return ans; 
    }
};