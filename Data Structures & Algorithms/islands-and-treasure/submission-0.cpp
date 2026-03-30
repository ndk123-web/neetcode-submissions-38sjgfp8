class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int i = 0 ; i < ROWS; i++) {
            for (int j = 0 ; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dirs = { {1,0} , {-1,0} , {0,-1} , {0,1} };

        while (!q.empty()) {
            auto [row,col] = q.front();
            q.pop();

            for (int i = 0 ; i < 4; i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];   

                if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = 1 + grid[row][col];
                q.push({r,c});
            }
        }

        return;
    }
};