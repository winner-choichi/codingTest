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
        queue<TreeNode*> q;

        q.push(root);

        int maxLevel = 1;
        int maxSum = root->val;

        int level = 1;
        while(!q.empty()) {
            int sz = q.size();
            int levelSum = 0;

            for (int i=0; i<sz; i++){
                TreeNode *currentNode = q.front();
                q.pop();

                levelSum+=currentNode->val;

                if(currentNode->left) q.push(currentNode->left);
                if(currentNode->right) q.push(currentNode->right);
            }

            if (levelSum > maxSum) {
                maxLevel = level;
                maxSum = levelSum;
            }

            level++;
        }

        return maxLevel;
    }
};
