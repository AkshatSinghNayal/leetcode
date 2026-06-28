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
        vector<int> ans;
        if (!root) return ans;

        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        int maxi = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            maxi = max(maxi, node->val);

            if (node->left) {
                mp[node].push_back(node->left);
                mp[node->left].push_back(node);
                q.push(node->left);
            }

            if (node->right) {
                mp[node].push_back(node->right);
                mp[node->right].push_back(node);
                q.push(node->right);
            }
        }

        vector<int> vis(maxi + 1, -1);

        queue<TreeNode*> q1;
        q1.push(target);
        vis[target->val] = 1;

        while (!q1.empty()) {

            if (k == 0) {
                while (!q1.empty()) {
                    ans.push_back(q1.front()->val);
                    q1.pop();
                }
                return ans;
            }

            int size = q1.size();

            while (size--) {
                TreeNode* node = q1.front();
                q1.pop();

                for (auto it : mp[node]) {
                    if (vis[it->val] == -1) {
                        q1.push(it);
                    }
                        vis[node->val] = 1;
                }
            }

            k--;
        }

        return ans;
    }
};