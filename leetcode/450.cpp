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
    pair<TreeNode*, TreeNode*> findKey(TreeNode* parent, TreeNode* root, int key) {
        if(!root) return {parent, nullptr};

        if(root->val == key) return {parent, root};
        
        return root->val > key ? findKey(root, root->left, key) : findKey(root, root->right, key);
    }

    TreeNode* deleteNode(TreeNode* root) {
        if (root->left) {
            TreeNode* parentNode = root;
            TreeNode* currentNode = root->left;
            while(true) {
                if (currentNode->right){
                    parentNode = currentNode;
                    currentNode = currentNode->right;
                } else {
                    break;
                }
            }
            
            if (currentNode->left) {
                if (parentNode == root) parentNode->left = currentNode->left;
                else parentNode->right = currentNode->left;
            } else {
                if (parentNode == root) parentNode->left = nullptr;
                else parentNode->right = nullptr;
            }

            currentNode->left = root->left;
            currentNode->right = root->right;

            return currentNode;
        } else if (root->right) {
            TreeNode* parentNode = root;
            TreeNode* currentNode = root->right;
            while(true) {
                if (currentNode->left){
                    parentNode = currentNode;
                    currentNode = currentNode->left;
                } else {
                    break;
                }
            }
            
            if (currentNode->right) {
                if (parentNode == root) parentNode->right = currentNode->right;
                else parentNode->left = currentNode->right;
            } else {
                if (parentNode == root) parentNode->right = nullptr;
                else parentNode->left = nullptr;
            }

            currentNode->left = root->left;
            currentNode->right = root->right;

            return currentNode;
        } else {
            return nullptr;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto [keyNodeParent, keyNode] = findKey(nullptr, root, key);

        if (!keyNode) return root;
        if (!keyNodeParent) {
            root = deleteNode(keyNode);
        } else {
            cout << keyNodeParent->val << " " << keyNode->val;
            if(keyNodeParent->val > key) {
                keyNodeParent->left = deleteNode(keyNode);
            } else {
                keyNodeParent->right = deleteNode(keyNode);
            }
        }

        return root;
    }
};
