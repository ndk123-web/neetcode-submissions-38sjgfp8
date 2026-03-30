class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int,int> mapp;

    void perm(vector<int>& nums, vector<int> part) {
        if (part.size() == nums.size()) {
            res.push_back(part);
            return;
        }

        for (auto& p : mapp) {
            if (mapp[p.first] > 0) {
                part.push_back(p.first);
                mapp[p.first]--;

                perm(nums,part);

                mapp[p.first]++;
                part.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        

        for (auto& num : nums) mapp[num]++;

        perm(nums,{});
        return res;      
    }
};