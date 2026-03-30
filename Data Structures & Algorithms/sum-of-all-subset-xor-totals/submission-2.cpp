class Solution {
private:
    int result = 0;

    void subset(int idx, vector<int>& nums, int currXor) {
        if (idx == nums.size()) {
            result += currXor;
            return;
        }

        subset(idx+1, nums, currXor ^ nums[idx]);
        subset(idx+1, nums, currXor);

        return;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        subset(0,nums,0);
        return result;   
    }
};