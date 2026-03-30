class Solution {
private:

    // storing to build n max product we are storing in memo
    unordered_map<int,int> memo;

    int dfs(int n) {
        if (n == 1) {
            return 1;
        }

        if (memo.count(n)) {
            return memo[n];
        }
        
        int res = 0;
        for (int i = 1; i < n; i++) {
            int val = max(i, dfs(i)) * max(n-i, dfs(n-i));
            res = max(res, val);
        }

        memo[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        return dfs(n);      
    }
};