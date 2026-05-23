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
    int dfs(TreeNode* root, long long accum, unordered_map<long long, int> &prefix, int targetSum) {
        if (!root) return 0;

        int cnt = 0;
        long long c_accum = accum + root->val;
        long long diff = c_accum - targetSum;
        cnt += prefix[diff];
        prefix[c_accum] += 1;

        cnt += dfs(root->left, c_accum, prefix, targetSum);
        cnt += dfs(root->right, c_accum, prefix, targetSum);

        prefix[c_accum] -= 1;
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;

        return dfs(root, 0, prefix, targetSum);
    }
};

