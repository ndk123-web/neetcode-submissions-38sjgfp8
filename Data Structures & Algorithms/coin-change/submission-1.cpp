class Solution {
private:
    unordered_map<int,int> memo;
    
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        if (memo.count(amount)) {
            return memo[amount];
        }

        int ans = INT_MAX;
        for (int& coin : coins) {
            
            int res = dfs(coins, amount - coin);

            if (res != INT_MAX) {
                ans = min(ans, 1 + res);
            }
        }

        memo[amount] = ans;
        return ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins,amount);
        return res == INT_MAX ? -1 : res;    
    }
};
