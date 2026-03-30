class Solution {
private:
    vector<vector<int>> res;

    void subset(int idx, vector<int>& nums, vector<int>& part){
        if (idx == nums.size()) {
            res.push_back(part);
            return;
        }

        part.push_back(nums[idx]);
        subset(idx+1,nums,part);

        part.pop_back();
        subset(idx+1,nums,part);

        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> part;
        subset(0,nums,part);
        return res;   
    }
};
