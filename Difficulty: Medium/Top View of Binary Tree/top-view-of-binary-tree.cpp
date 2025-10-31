class Solution {
  public:
  
    void helper(Node* root, int col, int depth, map<int, pair<int,int>> &mp) {
        if (!root) return; 
        
        // if this column not seen OR current node is higher up
        if (mp.find(col) == mp.end() || depth < mp[col].second) {
            mp[col] = {root->data, depth}; 
        }
        
        helper(root->left, col - 1, depth + 1, mp);
        helper(root->right, col + 1, depth + 1, mp);
    }
  
    vector<int> topView(Node *root) {
        vector<int> ans; 
        map<int, pair<int,int>> mp; 
       
        helper(root, 0, 0, mp);  // ✅ added depth param
       
        for (auto &it : mp) {
            ans.push_back(it.second.first); 
        }
       
        return ans; 
    }
};
