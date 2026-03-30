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
private:
    TreeNode* prev = nullptr;

    TreeNode* dfs(TreeNode* root, int target) {
        if (!root) return nullptr;

        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);

        if (root->val == target && !root->right && !root->left) {
            return nullptr;
        }
        
        return root;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};