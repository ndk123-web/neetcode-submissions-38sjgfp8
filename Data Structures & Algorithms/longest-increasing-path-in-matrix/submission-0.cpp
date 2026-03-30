class Solution {
private:
    int r, c;
    vector<vector<int>> dirs;
    map<pair<int,int>, int> memo;

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || j < 0 || i >= r || j >= c) {
            return 0;
        }

        if (memo.find({i,j}) != memo.end()) {
            return memo[{i,j}];
        }

        // take res = 1 as count current 
        int res = 1;
        for (vector<int>& dir : dirs) {
            int nr = dir[0] + i;
            int nc = dir[1] + j;

            if (nr >= 0 && nc >= 0 && nr < r && nc < c && matrix[nr][nc] > matrix[i][j]) {
                    res = max(res, 1 + dfs(matrix, nr,nc));
            }
        }
        memo[{i,j}] = res;
        return res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();

        dirs = { {1,0} , {0,1} , {-1,0}, {0,-1}};

        int res = 0;
        for (int i = 0 ; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int curr = dfs(matrix,i,j);
                res = max(res, curr);
            }
        }

        return res;    
    }
};
