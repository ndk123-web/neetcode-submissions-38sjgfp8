class Solution {
private:
    bool dfs(vector<int>& nums, int i, int target, int t) {

        // it means we didnt find
        if (i == nums.size()) {
            return false;
        }

        if (t == target) {
            return true;
        }
        // either take it or skip it

        return dfs(nums, i + 1, target, t + nums[i]) ||
               dfs(nums, i + 1, target, t);
    }

public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        return dfs(nums, 0, target, 0);
    }
};