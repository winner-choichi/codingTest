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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int depth = 1;
        int max_d = depth;
        stack<pair<TreeNode*, int>> st;
        st.push({root, depth});

        while (!st.empty()) {
            // cout << st.top().first->val << '\n';
            auto [current, current_d] = st.top();
            if (current_d > max_d) max_d = current_d;
            st.pop();
            if (current->right!=nullptr) st.push({current->right, current_d+1});
            if (current->left!=nullptr) st.push({current->left, current_d+1});
        }

        return max_d;
        
    }
};

