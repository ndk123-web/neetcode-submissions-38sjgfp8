class Solution {
private:
    vector<vector<int>> res;

    void comb(vector<int>& nums, int remain, int idx, vector<int>& part) {
        if (remain < 0) return;
        if (remain == 0) {
            res.push_back(part);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i-1] == nums[i]) continue;
            part.push_back(nums[i]);
            comb(nums,remain-nums[i],i+1,part);
            part.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> part;
        sort(candidates.begin(),candidates.end());
        comb(candidates,target,0,part);
        return res;
    }
};
