class Solution {
private:
    vector<vector<int>> dp;

    int dfs(vector<int>& coins, int amount, int i) {
        if (amount == 0) {
            return 1;
        }
        
        if (i >= coins.size() || amount < 0) {
            return 0;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int take = 0;
        if (coins[i] <= amount) {
            take = dfs(coins,amount-coins[i],i);  // reuse
        }

        int skip = dfs(coins, amount,i+1);
        return dp[i][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(coins.size(), vector<int>(amount+1, -1));

        int res = dfs(coins, amount, 0);
        return res == -1 ? 0 : res;
    }
};
