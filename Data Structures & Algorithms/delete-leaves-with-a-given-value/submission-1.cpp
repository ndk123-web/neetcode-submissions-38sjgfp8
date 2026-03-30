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
    bool isRootLeaf = false;

    void dfs(TreeNode*& root, int target , TreeNode* prev, int isLeft) {
        if (!root) return;

        dfs(root->left,target,root,1);
        dfs(root->right,target,root,0);

        if (target == root->val && !root->left && !root->right) {
            if (prev) {
                if (isLeft == 1) {
                    prev->left = nullptr;
                }
                else if (isLeft == 0) {
                    prev->right = nullptr;
                }
            }
            else {
                isRootLeaf = true;
                root = nullptr;
            }
        }

        return;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (isRootLeaf) return nullptr;
        dfs(root,target,nullptr,3);
        return root;
    }
};