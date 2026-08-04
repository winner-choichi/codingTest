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
    int longestZigZag(TreeNode* root) {
        enum class Direction {
            Root,
            Left,
            Right,
        };
        stack<tuple<TreeNode*, int, Direction>> st;
        st.push({root, 0, Direction::Root});

        int ans = 0;
        while (!st.empty()) {
            auto [currentNode, z_depth, d] = st.top();
            st.pop();

            ans = max(ans, z_depth);

            if (currentNode->left) {
                int left_z_depth=1;
                if (d==Direction::Root || d==Direction::Right) left_z_depth = z_depth+1;
                st.push({currentNode->left, left_z_depth, Direction::Left});
            } 
            if (currentNode->right) {
                int right_z_depth=1;
                if (d==Direction::Root || d==Direction::Left) right_z_depth = z_depth+1;
                st.push({currentNode->right, right_z_depth, Direction::Right});
            }
        }

        return ans;
    }
};
