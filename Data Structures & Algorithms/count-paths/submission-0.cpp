class Solution {
private:
    int R, C;
    int dfs(vector<vector<int>>& dp, int r, int c) {
        if (r == 0 || c == 0) {
            return 1;
        }

        if (dp[r][c] != -1) {
            return  dp[r][c];
        }

        // we can go either left or top 
        dp[r][c] = dfs(dp,r-1,c) + dfs(dp, r, c-1);
        return dp[r][c];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }   

        for (int i = 0 ; i < n; i++) {
            dp[0][i] = 1;
        }
        
        /*
            1 1 1
            1 0 0
            1 0 0
        */
        return dfs(dp, m-1, n-1);
    }
};
