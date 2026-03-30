class Solution {
private:

    int dfs(vector<vector<int>>& dp, int r, int c) {
        if (r < 0 || c < 0 || dp[r][c] == -1) {
            return 0;
        }

        if (dp[r][c] > 0) {
            return dp[r][c];
        }

        dp[r][c] = dfs(dp, r-1,c) + dfs(dp, r, c-1);
        return dp[r][c];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // filter
        for (int i = 0 ; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = -1;
                }
            }
        }

        bool isAppear = false;
        for (int i = 0 ; i < m; i++) {
            if (!isAppear) {
                if (dp[i][0] == -1) {
                    isAppear = true;
                } else {
                    dp[i][0] = 1;
                }
            }
        }

        isAppear = false;
        for (int i = 0 ; i < n; i++) {
            if (!isAppear) {
                if (dp[0][i] == -1) {
                    isAppear = true;
                } else {
                    dp[0][i] = 1;
                }
            }
        }

        return dfs(dp, m-1, n-1);   
    }
};