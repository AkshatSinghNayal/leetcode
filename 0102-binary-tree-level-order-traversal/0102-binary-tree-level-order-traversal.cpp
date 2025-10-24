class Solution {
public:
    void levelHelp(TreeNode* root, vector<vector<int>>& ans, int level) {

        if( root == nullptr) return ; 
        if(ans.size()==level){
            ans.push_back({}); 
        }

        ans[level].push_back(root->val); 
        levelHelp( root->left , ans , level+1 ); 
        levelHelp( root->right , ans , level+1 ); 

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelHelp(root, ans, 0);
        return ans;
    }
};
