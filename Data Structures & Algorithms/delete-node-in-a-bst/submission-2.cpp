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
    TreeNode* deleteN(TreeNode* root,int key) {
        if (!root) return root;

        if (root->val > key) {
            root->left = deleteN(root->left,key);
        }
        else if (root->val < key) {
            root->right = deleteN(root->right,key);
        }
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // if both there 
            TreeNode* curr = root->right;
            while(curr->left) curr=curr->left;

            root->val = curr->val;
            root->right = deleteN(root->right,root->val);
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteN(root,key);
    }
};