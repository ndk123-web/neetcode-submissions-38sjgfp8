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
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0,0};

        pair<int,int> l= dfs(root->left);
        pair<int,int> r= dfs(root->right);

        int withRoot = root->val + l.second + r.second;
        int withoutRoot = max(l.first,l.second) + max(r.first,r.second);

        return {withRoot,withoutRoot};
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return max(res.first,res.second);
    }
};