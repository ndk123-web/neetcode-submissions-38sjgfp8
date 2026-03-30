class Solution {
private: 
    vector<vector<int>> dp;

    // 0 1 2 3
    // 1 1 5 1 (10)

    int dfs(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = 0;

        // 1 -> =2
        // 1. k = 1 (1*1*5) + (0) + 5 = 10
        for (int k = i; k <= j; k++) {
            int prodBallon = nums[k] * nums[i-1] * nums[j + 1];
            int currRes = dfs(nums, i, k - 1) + prodBallon + dfs(nums, k + 1, j);

            res = max(res, currRes);
        }

        return dp[i][j] = res;
    }


public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newnums(n + 2, 0);
        dp.assign(n + 1, vector<int>(n+1, -1));

        for (int i = 1; i <= n; i++) {
            newnums[i] = nums[i-1];
        }      

        // neutral values
        newnums[0] = 1;
        newnums[newnums.size() - 1] = 1;

        return dfs(newnums, 1, newnums.size() - 2);
    }
};
