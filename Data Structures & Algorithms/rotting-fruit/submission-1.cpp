class Solution {
private:
    queue<pair<int,int>> q;
    int fresh;
    int ROWS, COLS;

public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        fresh = 0;

        for (int i = 0 ; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;
        vector<vector<int>> dirs = { {1,0} , {-1,0} , {0,1} , {0,-1} };

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;

            for (int i = 0 ; i < size; i++) {
                auto [r,c] = q.front();
                q.pop();

                for (int j = 0 ; j < 4; j++) {
                    int nr = r + dirs[j][0];
                    int nc = c + dirs[j][1];

                    if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] != 1) {
                        continue;
                    }

                    fresh--;
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
