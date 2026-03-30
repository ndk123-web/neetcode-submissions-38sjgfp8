class Solution {
private:
    vector<vector<int>> res;

    void perm(vector<int>& nums, vector<int> part) {
        if (nums.empty()) {
            res.push_back(part);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i-1]) continue;

            part.push_back(nums[i]);
            
            vector<int> newnums(nums.begin(),nums.end());
            newnums.erase(newnums.begin()+i);

            perm(newnums,part);

            part.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        perm(nums,{});
        return res;   
    }
};