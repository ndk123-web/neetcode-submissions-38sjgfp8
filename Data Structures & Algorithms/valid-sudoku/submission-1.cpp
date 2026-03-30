class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<char> sett;
        int row = board.size();
        int col = board[0].size();

        // check row wise
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '.') continue;
                if (sett.find(board[i][j]) != sett.end()) {
                    return false;
                }
                sett.insert(board[i][j]);
            }
            sett.clear();
        }

        // check the column wise
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0; j < col; j++) {
                if (board[j][i] == '.') continue;
                if (sett.find(board[j][i]) != sett.end()) {
                    return false;
                }
                sett.insert(board[j][i]);
            }
            sett.clear();
        }

        sett.clear();

        // check in 3*3 matrix of 9*9
        int increamentCount = 3;
        int incRow = 3;
        int r1 = 0 , c1 = 0 , r2 = 2 , c2 = 2;
        
        for (int i = 0 ; i < 9; i++) {
            unordered_set<char> tSet;
            for (int j = r1; j <= r2; j++) {
                for (int k = c1; k <= c2; k++) {
                    if (board[j][k] == '.') continue;
                    if (tSet.find(board[j][k]) != tSet.end()) {
                        return false;
                    }
                    tSet.insert(board[j][k]);
                }
            }
            
            incRow--;

            if (incRow == 0) {
                r1 = r1 + increamentCount;
                r2 = r2 + increamentCount;
                incRow = 3;
                c1 = 0;
                c2 = 2;
                // tSet.clear();
                continue;
            }

            c1 = c1 + increamentCount;
            c2 = c2 + increamentCount;
            tSet.clear();
        }

        return true;
    }
};
