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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long maxi ; 
        vector<long long> ans  ;
        queue<TreeNode*> q ; 
        q.push(root); 
        while(!q.empty()){
            int size= q.size(); 
            long long sum= 0;

            for( int i = 0; i<size ; i++){
                auto node= q.front();
                sum+=node->val;
                q.pop(); 

                if( node->left ) q.push(node->left); 
                if( node->right) q.push( node->right ) ; 


            }
            ans.push_back( sum ); 

            

        }
        if( k > ans.size() ) return -1; 
        sort(ans.begin(),ans.end()); 
        int n = ans.size(); 
        maxi = ans[n-k]; 
        return maxi ; 
    }
};