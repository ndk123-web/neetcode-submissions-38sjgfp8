class Solution {
private:
    vector<vector<char>> board;
    string word;

    bool backtrack(int r, int c, int idx) {
        if (idx == word.size())
            return true;

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            board[r][c] == '#' || board[r][c] != word[idx])
            return false;

        board[r][c] = '#';
        bool res = backtrack(r + 1, c, idx + 1) ||
                   backtrack(r - 1, c, idx + 1) ||
                   backtrack(r, c + 1, idx + 1) || 
                   backtrack(r, c - 1, idx + 1);

        board[r][c] = word[idx];

        return res;
    }

    bool helper(int row, int col) {
        int i = 0, j = 0;

        while (i < row) {
            if (j >= col) {
                i++;
                j = 0;
            }
            if (backtrack(i, j, 0)) {
                return true;
            }
            j++;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        this->board = board;
        this->word = word;

        return helper(row, col);
    }
};