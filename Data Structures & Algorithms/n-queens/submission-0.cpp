class Solution {
private:
    vector<vector<string>> res;

    bool isSafe(vector<string>& mat, int row, int col) {
        int duprow = row;
        int dupcol = col;

        while (row >= 0) {
            if (mat[row][col] == 'Q') return false;
            row--;
        }

        row = duprow;
        while (col >= 0 && row >= 0) {
            if (mat[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (col < mat.size()  && row >= 0) {
            if (mat[row][col] == 'Q') return false;
            row--;
            col++;
        }

        return true;
    }

    void putQueen(vector<string>& mat, int row) {
        
        if (row == mat.size()) {
            res.push_back(mat);
            return;
        }

        for (int col = 0 ; col < mat.size(); col++) {
            if (isSafe(mat,row,col)) {
                mat[row][col] = 'Q';
                putQueen(mat,row+1);
                mat[row][col] = '.';
            }
        }

        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> mat(n);

        string s(n,'.');
        for (int i = 0 ; i < n; i++) {
            mat[i] = s;
        }

        putQueen(mat,0);    
        return res;
    }
};
