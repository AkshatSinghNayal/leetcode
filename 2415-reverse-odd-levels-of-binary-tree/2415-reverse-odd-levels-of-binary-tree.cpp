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

    void solve( vector<TreeNode*>& temp , int i , int j ){
        while(i<j){
            swap(temp[i]->val , temp[j]->val );
            i++ ; j--; 
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q; int level = 0; 
        q.push(root);

        while(!q.empty()){
            int size = q.size(); 
            vector<TreeNode*> temp; 
            for(int i  = 0 ;i< size ; i++ ){
                auto node = q.front() ; q.pop(); 

                if(node->left){
                    temp.push_back(node->left);
                    q.push(node->left); 
                }
                if(node->right){
                    temp.push_back(node->right); 
                    q.push(node->right); 
                }

            }
            if(level %2 == 0) solve(temp ,0, temp.size()-1); 

            level++; 
        }
        return root; 
    }
};