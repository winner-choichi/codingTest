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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        vector<int> res;

        while (!q.empty()) {
            auto [current, current_d] = q.front();
            q.pop();

            if (res.size() >= current_d) res[current_d-1] = current->val;
            else res.push_back(current->val);

            if(current->left != nullptr) q.push({current->left, current_d + 1});
            if(current->right != nullptr) q.push({current->right, current_d + 1});
        }

        return res;
        
    }
};

