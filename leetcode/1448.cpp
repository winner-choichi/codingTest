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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        int cnt=0;
        while(!q.empty()) {
            auto [c_node, max] = q.front();
            q.pop();
            // cout << 'val: ' << c_node->val << ' max: ' << max << '\n';
            if (c_node->val == max) cnt++;

            if(c_node->left) {
                if (c_node->left->val > max) {
                    q.push({c_node->left, c_node->left->val});
                } else {
                    q.push({c_node->left, max});
                }
            }
            if(c_node->right) {
                if (c_node->right->val > max) {
                    q.push({c_node->right, c_node->right->val});
                } else {
                    q.push({c_node->right, max});
                }
            }
        }

        return cnt;
        
    }
};

