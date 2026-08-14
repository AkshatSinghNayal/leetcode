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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,vector<TreeNode*>>mp; 
       queue<TreeNode*>q; 
       TreeNode* found= nullptr;
       q.push(root);

       while(!q.empty()){
            int size = q.size(); 
            for(int i = 0 ; i<size ; i++ ){
                auto node = q.front(); q.pop(); 
                if( node == target ){
                    found = node;
                }
                if( node->left){
                    mp[node].push_back(node->left); 
                    mp[node->left].push_back(node); 
                    q.push(node->left);
                }

                if( node->right ){
                    mp[node].push_back(node->right); 
                    mp[node->right].push_back(node); 
                    q.push(node->right);
                }
            }
       }
        queue<pair<TreeNode* , TreeNode*>> q1;
        q1.push({ nullptr , found}); 
        int dist = 0; 
        vector<int>ans; 

        while(!q1.empty()){
            int size = q1.size(); 
            if( dist ==  k ){
                while(!q1.empty()){
                    // cout<<q1.front().second->val << " " ;
                    ans.push_back(q1.front().second->val ); q1.pop(); 
                }
                break;
            }
            for(int i  = 0;i<size ; i++ ){
                auto [parent , node] = q1.front() ; q1.pop(); 

                for(auto& it : mp[node]){
                    if( parent  == it ) continue;
                    q1.push({ node , it }); 
                }

            }
            
            dist++; 
        }
        return ans; 
    }
};