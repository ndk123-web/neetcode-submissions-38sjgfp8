class Solution {
private:
    // min heap
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minheap;
    vector<vector<int>> dirs;
    int ROWS, COLS;
    vector<vector<bool>> visited;

    bool isValid(int r, int c) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c]) {
            return false;
        }   

        return true;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int res = 0;
        dirs = { {0,1} , {0,-1} , {1,0} , {-1,0} };
        ROWS = grid.size();
        COLS = grid[0].size();
        visited.assign(ROWS, vector<bool>(COLS, false));

        // start from 0 , (0,0)
        minheap.push({grid[0][0], {0,0}});

        while (!minheap.empty()) {
            pair<int, pair<int,int>> top = minheap.top();
            minheap.pop();

            int sr = top.second.first;
            int sc = top.second.second;

            if (sr == ROWS - 1 && sc == COLS - 1) {
                return max(res,grid[sr][sc]);
            }

            if (visited[sr][sc]) {
                continue;
            }

            visited[sr][sc] = true;
            res = max(res, top.first);

            // we need to go 4 direction
            for (vector<int>& dir : dirs) {
                int nr = sr + dir[0];
                int nc = sc + dir[1];

                if (!isValid(nr,nc)) {
                    continue;
                }

                minheap.push({grid[nr][nc], {nr,nc}});
            }
        }   

        return 0; 
    }
};
