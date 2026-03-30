class Solution {
private:
    int maxArea;
    int ROWS, COLS;

    int dfs(vector<vector<int>>& grid, int r , int c, int count) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0) {
            return 0;
        }

        // 1 1
        // 1 1
        grid[r][c] = 0;
        int ans = 1 + dfs(grid,r+1,c,count+1) + dfs(grid,r-1,c,count+1) + dfs(grid,r,c+1,count+1) + dfs(grid,r,c-1,count+1);

        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxArea = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0 ; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    int ans = dfs(grid,i,j,1);
                    maxArea = max(maxArea,ans);
                }
            }
        }

        return maxArea;    
    }
};
