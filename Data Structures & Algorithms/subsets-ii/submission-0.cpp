class Solution {
private:
    vector<vector<int>> nodupRes;

    void subset(vector<int>& nums, vector<int> part, int idx) {

        nodupRes.push_back(part);
        
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i-1] == nums[i]) continue;

            part.push_back(nums[i]);
            subset(nums,part,i+1);
            part.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        subset(nums,{},0);
        return nodupRes;
    }
};
