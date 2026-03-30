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
    int count = 1;

    void good(TreeNode* root,vector<int>& path) {
        if (!root) return;

        int max_val = path.empty() ? root->val : *max_element(path.begin(),path.end());

        if (max_val <= root->val) count++;

        path.push_back(root->val);

        good(root->left,path);
        good(root->right,path);
        path.pop_back();

        return;
    }

public:
    int goodNodes(TreeNode* root) {
        vector<int> path;
        good(root,path);
        return count - 1;
    }
};
