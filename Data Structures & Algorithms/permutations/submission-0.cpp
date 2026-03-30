class Solution {
private:
    vector<vector<int>> res;
    
    void perm(vector<int>& nums, vector<int> part) {
        if (nums.empty()) {
            res.push_back(part);
            return;
        }

        for (int i = 0 ; i < nums.size(); i++) {
            part.push_back(nums[i]);

            vector<int> newnums(nums.begin(),nums.end());
            newnums.erase(newnums.begin()+i);

            perm(newnums,part);
            
            part.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,{});
        return res;   
    }
};
