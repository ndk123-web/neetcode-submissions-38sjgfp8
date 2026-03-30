class Solution {
private:
    vector<vector<int>> res;
    vector<int> part;

    void subset(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(part);
            return;
        }

        part.push_back(nums[idx]);
        subset(idx+1, nums);

        part.pop_back();
        subset(idx+1, nums);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        subset(0,nums);
        return res;
    }
};