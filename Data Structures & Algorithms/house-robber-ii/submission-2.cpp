class Solution {
private:
    vector<int> memo;

    int dfs(vector<int>& nums, int i, int n) {
        if (i > n) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = max(dfs(nums,i+1,n), dfs(nums,i+2,n) + nums[i]);
        return memo[i];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        memo.assign(n,-1);
        int f = dfs(nums,0,n-2);
        
        memo.assign(n,-1);
        int s = dfs(nums,1,n-1);
        
        return max(f,s);
    }
};
