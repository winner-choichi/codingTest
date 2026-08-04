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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        int ans = 1;
        int maxSum = root->val;
        int currentLevel = 1;
        int currentSum = 0;
        while(!q.empty()) {
            auto [currentNode, currentDepth] = q.front();
            q.pop();

            if (currentLevel != currentDepth) {
                if (maxSum < currentSum) {
                    ans = currentLevel;
                    maxSum = currentSum;
                }
                currentLevel = currentDepth;
                currentSum = 0;
            }

            currentSum+=currentNode->val;

            if (currentNode->left) {
                q.push({currentNode->left, currentDepth+1});
            }
            if (currentNode->right) {
                q.push({currentNode->right, currentDepth+1});
            }
        }
        // for the last level
        if (maxSum < currentSum) {
            ans = currentLevel;
            maxSum = currentSum;
        }

        return ans;
    }
};
