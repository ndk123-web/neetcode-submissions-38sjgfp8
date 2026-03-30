class Solution {
private:
    vector<int> arr;

    void generate(TreeNode* root) {
        if (!root) return;

        generate(root->left);
        arr.push_back(root->val);
        generate(root->right);

        return;
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        generate(root);

        for (int i = 0 ; i < arr.size() - 1; i++) {
            if (arr[i] >= arr[i+1]) return false;
        }   

        return true;
    }
};