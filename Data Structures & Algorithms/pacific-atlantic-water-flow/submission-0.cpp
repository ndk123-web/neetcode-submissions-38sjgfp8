class Solution {
private:
    vector<vector<int>> res;
    vector<vector<int>> dirs;
    int ROWS , COLS;
    bool atlantic , pacific;

    void dfs(vector<vector<int>>& heights, int r, int c, int prev) {
        if (r < 0 || c < 0) {
            pacific = true;
            return;
        }
        if (r >= ROWS || c >= COLS) {
            atlantic = true;
            return;
        }

        if (heights[r][c] > prev) {
            return;
        }

        int temp = heights[r][c];
        heights[r][c] = INT_MAX;

        for (auto& dir : dirs) {
            dfs(heights,r+dir[0],c+dir[1],temp);
            if (pacific && atlantic) {
                break;
            }
        }
        heights[r][c] = temp;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        dirs = { {1,0} , {-1,0} , {0,1} , {0,-1} };

        for (int i = 0 ; i < ROWS; i++) {
            for (int j = 0 ; j < COLS; j++) {
                pacific = false;
                atlantic = false;
                dfs(heights,i,j,INT_MAX);
                if (atlantic && pacific) {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
