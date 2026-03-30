class Solution {
private:
    set<vector<int>> res;

    void sub(vector<int>& nums,vector<int> part, int idx) {
        if (idx == nums.size()) {
            res.insert(part);
            return;
        }

        part.push_back(nums[idx]);
        sub(nums,part,idx+1);
        part.pop_back();
        sub(nums,part,idx+1);

        return;
    }  
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        sub(nums,{},0);
        return vector<vector<int>>(res.begin(),res.end());
    }
};
