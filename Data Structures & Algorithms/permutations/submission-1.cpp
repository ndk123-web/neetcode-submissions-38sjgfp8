class Solution {
private:
    vector<vector<int>> res;
    
    void perm(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx ; i < nums.size(); i++) {
            swap(nums[idx],nums[i]);
            perm(nums,idx+1);
            swap(nums[idx],nums[i]);
        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0);
        return res;   
    }
};
