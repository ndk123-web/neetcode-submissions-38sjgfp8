class Solution {
private:
    vector<vector<int>> res;

    void comb(vector<int>& nums, int idx, int remain, vector<int>& part) {
        if (remain < 0) return;

        if (remain == 0) {
            res.push_back(part);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            part.push_back(nums[i]);
            comb(nums, i, remain - nums[i], part); // reuse allowed
            part.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> part;
        comb(nums, 0, target, part);
        return res;
    }
};
