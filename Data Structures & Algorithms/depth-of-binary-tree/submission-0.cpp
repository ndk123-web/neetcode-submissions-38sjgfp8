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
    int deep(TreeNode* node, int d) {
        if (!node) return d-1;
        else if (!node->left && !node->right) return d;

        return max(deep(node->left,d+1),deep(node->right,d+1));
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return deep(root,1);
    }
};