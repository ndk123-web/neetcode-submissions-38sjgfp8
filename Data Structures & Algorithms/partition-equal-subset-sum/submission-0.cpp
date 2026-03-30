class Solution {
private:

    int minTarget;

    bool dfs(vector<int>& nums, int index, int target) {
        
        if (target == minTarget) {
            return true;
        }

        if (index >= nums.size()) {
            return false;
        }

        for (int i = index; i < nums.size(); i++) {

            int res = target + nums[i];
            
            if (res > minTarget) {
                continue;
            }   
            
            if (dfs(nums, i+1, res)) {
                return true;
            }
            
        }

        return false;
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        minTarget = totalsum / 2;

        if (totalsum % 2 != 0) {
            return false;
        }

        return dfs(nums, 0, 0);
    }
};
