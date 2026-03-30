class Solution {
private:

    bool backtrack(vector<vector<char>>& board, int r, int c, string word, int idx) {
        if (idx == word.size()) 
            return true;

        if (r >= board.size() || c >= board[0].size() || board[r][c] != word[idx] || board[r][c] == 'N' || r < 0 || c < 0) 
            return false;

        char t = board[r][c];
        board[r][c] = 'N';

        bool top = backtrack(board,r-1,c,word,idx+1);
        bool bottom = backtrack(board,r+1,c,word,idx+1); 
        bool left= backtrack(board,r,c-1,word,idx+1);  
        bool right= backtrack(board,r,c+1,word,idx+1); 

        board[r][c] = t;

        return top || bottom || left || right;
    }

    bool helper(vector<vector<char>>& board, int row, int col, string word) {
        int i = 0;
        int j = 0;

        while (i < row) {
            if (j >= col) {
                i++;
                j=0;
            }
            if (backtrack(board,i,j,word,0)) {
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

        return helper(board,row,col,word);
    }
};
