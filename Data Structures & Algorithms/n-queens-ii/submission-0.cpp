class Solution {
private:
    int cnt = 0;

    bool isSafe(vector<string>& board, int row, int col) {
        int dr = row , dc = col;

        while (row >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
        }

        row = dr;
        while (row >=0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = dr;
        col = dc;
        while (row >=0 && col < board[0].size()) {
            if (board[row][col] == 'Q') return false;
            row--;
            col++;
        }

        return true;
    }
    
    void putQueen(vector<string>& board, int row) {
        if (row == board.size()) {
            cnt++;
            return;
        }

        for (int col = 0 ; col < board[0].size(); col++) {
            if (isSafe(board,row,col)) {
                board[row][col] = 'Q';
                putQueen(board,row+1);
                board[row][col] = '.';
            }
        }

        return;
    }

public:
    int totalNQueens(int n) {
        vector<string> board;

        for (int i = 0 ; i < n ; i++) {
            board.push_back(string(n,'.'));
        }

        putQueen(board,0);
        return cnt;
    }
};