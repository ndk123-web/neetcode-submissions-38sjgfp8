class Solution {
private:
    unordered_map<int, int> memo;

    int dfs(vector<int>& nums, int t, int target,int idx) {
        if (t > target || idx >= nums.size()) {
            return -1;
        }

        if (t == target) {
            return 1;
        }

        if (memo.count(t)) {
            return memo[t];
        }

        int ways = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            int res = dfs(nums,t+nums[i],target,0);

            if (res != -1) {
                ways += res;
            }
        }

        memo[t] = ways;
        return memo[t];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums,0,target,0);
    }
};