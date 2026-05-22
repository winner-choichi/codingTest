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
    struct Node {
        TreeNode* node_ptr;
        vector<long long int> sum_list;
    };
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int cnt = 0;
        stack<Node> s;

        if (root->val==targetSum) cnt++;
        s.push(Node{root, {root->val}});
        while (!s.empty()) {
            Node c_node = s.top();
            s.pop();

            vector<long long int>& c_sum_list = c_node.sum_list;
            if(c_node.node_ptr->left) {
                int l_val = c_node.node_ptr->left->val;
                vector<long long int> l_sum_list = {l_val};
                for (long long int i: c_sum_list) {
                    l_sum_list.push_back(i+l_val);
                }
                for (long long int i: l_sum_list) {
                    if (i==targetSum) cnt++;
                }
                s.push(Node{c_node.node_ptr->left, l_sum_list});
            }
            if(c_node.node_ptr->right) {
                int r_val = c_node.node_ptr->right->val;
                vector<long long int> r_sum_list = {r_val};
                for (long long int i: c_sum_list) {
                    r_sum_list.push_back(i+r_val);
                }
                for (long long int i: r_sum_list) {
                    if (i==targetSum) cnt++;
                }
                s.push(Node{c_node.node_ptr->right, r_sum_list});
            }
        }
        
        return cnt;
    }
};

