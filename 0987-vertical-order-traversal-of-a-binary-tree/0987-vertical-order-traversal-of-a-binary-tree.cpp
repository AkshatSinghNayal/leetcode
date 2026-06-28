class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> row -> nodes
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q; // node, row, col
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node , col , row] = q.front(); q.pop(); 
            nodes[col][row].insert(node->val); 

            if(node->left) q.push({node->left,col-1,row+1}); 
            if(node->right) q.push({node->right,col+1,row+1}); 
        }
        vector<vector<int>>ans;

        for (auto &[col, rowMap] : nodes) {
            vector<int> colNodes;
            for (auto &[row, vals] : rowMap) {
                colNodes.insert(colNodes.end(), vals.begin(), vals.end());
            }
            ans.push_back(colNodes);
        }
        
        return ans;
    }
};
