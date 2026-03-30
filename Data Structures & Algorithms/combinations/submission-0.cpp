class Solution {
private:
    vector<vector<int>> res;

    void comb(vector<int>& nums, vector<int> part, int k , int idx) {
        if (part.size() == k) {
            res.push_back(part);
            return;
        }

        for (int i = idx; i < nums.size(); i++){ 
            part.push_back(nums[i]);
            comb(nums,part,k,i+1);
            part.pop_back();
        }   
        
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        for (int i = 1; i <= n; i++) nums[i-1] = i;

        comb(nums,{},k,0);
        return res;
    }
};