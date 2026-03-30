class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> pac;
    vector<vector<bool>> atl;
    vector<vector<int>> res;
    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;

        for (auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        pac = vector<vector<bool>>(ROWS, vector<bool>(COLS,false));
        atl = vector<vector<bool>>(ROWS, vector<bool>(COLS,false));

        for (int c = 0; c < COLS; c++) {
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }

        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }

        for (int i = 0 ; i < ROWS; i++) {
            for (int j = 0 ; j < COLS; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};