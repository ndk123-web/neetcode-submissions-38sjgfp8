class Solution {
private:
    vector<vector<int>> dirs;
    int ROWS, COLS;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            dfs(nr,nc,board);
        }

        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int r = 0 ; r < ROWS; r++) {
            // if (board[r][0] == 'O') {
                dfs(r,0,board);
            
            // if ?(board[r][COLS-1] == 'O') {
                dfs(r,COLS-1,board);
            // }
        }

        for (int c = 0 ; c < COLS; c++) {
            // if (board[0][c] == 'O') {
                dfs(0,c,board);
            // }
            // if (board[ROWS-1][c] == 'O') {
                dfs(ROWS-1,c,board);
            // }
        }

        for (int r = 0 ; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
                else if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }

        return;
    }
};
