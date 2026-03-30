class Solution {
private:
    vector<vector<int>> res;
    void perm(vector<int>& nums, vector<int> part, int idx){
        if (nums.empty()){
            res.push_back(part);
            return;
        }

        for (int i= 0; i < nums.size(); i++){
            part.push_back(nums[i]);
            vector<int> newnums(nums.begin(),nums.end());
            newnums.erase(newnums.begin()+i);

            perm(newnums,part,i);
            part.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,{},0);
        return res;
    }
};
