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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_1, leaf_2;
        stack<TreeNode*> st1, st2;

        st1.push(root1);
        st2.push(root2);

        while(!st1.empty()) {
            TreeNode* current = st1.top();
            st1.pop();
            if (current->right!=nullptr) st1.push(current->right);
            if (current->left!=nullptr) st1.push(current->left);

            if (current->right==nullptr && current->left==nullptr) leaf_1.push_back(current->val);
        }

        while(!st2.empty()) {
            TreeNode* current = st2.top();
            st2.pop();
            if (current->right!=nullptr) st2.push(current->right);
            if (current->left!=nullptr) st2.push(current->left);

            if (current->right==nullptr && current->left==nullptr) leaf_2.push_back(current->val);
        }

        if (leaf_1.size() != leaf_2.size()) return false;
        for (int i=0; i<leaf_1.size(); ++i) {
            if (leaf_1[i]!=leaf_2[i]) return false;
        }

        return true;
        
    }
};

