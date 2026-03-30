class Solution {
private:
    int m, n;
    unordered_map<string, int> memo;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0) {
            return INT_MAX;
        }

        if (r == 0 && c == 0) {
            return grid[r][c];
        }

        string key = to_string(r) + "," + to_string(c);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int res = 0;
        res += min(dfs(grid, r, c - 1), dfs(grid, r - 1, c)) + grid[r][c];
        memo[key] = res;
        return res;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        return dfs(grid, m - 1, n - 1);
    }
};