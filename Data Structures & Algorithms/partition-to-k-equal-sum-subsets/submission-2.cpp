class Solution {
private:
    vector<bool> used;
    int target;

    bool backtrack(vector<int>& nums, int k, int cSum, int st) {
        if (k == 1)
            return true;
        if (cSum == target)
            return backtrack(nums, k - 1, 0, 0);

        for (int i = st; i < nums.size(); i++) {
            if (used[i] || nums[i] + cSum > target)
                continue;

            used[i] = true;

            if (backtrack(nums, k, cSum + nums[i], i + 1))
                return true;
            
            used[i] = false;

            if (cSum == 0)
                break;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;

        used.assign(nums.size(), false);
        target = sum / k;

        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target)
            return false;

        return backtrack(nums, k, 0, 0);
    }
};