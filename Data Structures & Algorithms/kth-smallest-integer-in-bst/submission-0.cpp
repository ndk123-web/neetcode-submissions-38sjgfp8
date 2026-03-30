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
    vector<int> nums;

    void generate(TreeNode* root) {
        if (!root) return;

        generate(root->left);
        nums.push_back(root->val);
        generate(root->right);

        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        generate(root);

        return nums[k-1];
    }
};
