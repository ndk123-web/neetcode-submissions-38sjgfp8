class Solution {
private:
    vector<vector<int>> grid;
    int minValue;
    int ROWS, COLS;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs;

    void dfs(int h, int r, int c) {
        if (r == ROWS - 1 && c == COLS - 1) {
            minValue = min(h, minValue);
            return;
        }

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) {
            return;
        }

        if (visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        int res = max(h, grid[r][c]);
        
        //go 4 direction
        for (vector<int>& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr < ROWS && nc < COLS && nr >=0 && nc >=0) {
                dfs(max(grid[nr][nc],h), nr,nc);
            }
        }

        // backtrack
        visited[r][c] = false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));
        minValue = INT_MAX;
        this->grid = grid;
        dirs = { {0,1} , {0,-1} , {1,0} , {-1,0} };

        dfs(grid[0][0],0,0);
        return minValue;    
    }
};
