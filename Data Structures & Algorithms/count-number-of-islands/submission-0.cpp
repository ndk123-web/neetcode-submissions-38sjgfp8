class Solution {
private:
    int count;

    void isLand(vector<vector<char>>& grid,int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        isLand(grid,r-1,c);
        isLand(grid,r+1,c);
        isLand(grid,r,c-1);
        isLand(grid,r,c+1);
    }

    void helper(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                   count++;
                   isLand(grid,i,j);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        count = 0;

        helper(grid);
        return count;    
    }
};
