class Solution {
private:
    map<pair<int,int>, int> memo;

    int gtarget;
    int dfs(vector<int>& nums, int target, int i) {
        if (i >= nums.size() && target == gtarget) {
            return 1;
        }

        if (i >= nums.size()) {
            return INT_MAX;
        }

        if (memo.find({i,target}) != memo.end()) {
            return memo[{i,target}];
        }

        int count = 0;
        
        // we have 2 choices + / -
        int sub = dfs(nums,-nums[i]+target,i+1);
        int add = dfs(nums,nums[i]+target,i+1);

        if (add != INT_MAX) {
            count = count + add;
        }
        if (sub != INT_MAX) {
            count = count + sub;
        }

        return memo[{i,target}] = count;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        gtarget = target;
        return dfs(nums,0,0);        
    }
};
