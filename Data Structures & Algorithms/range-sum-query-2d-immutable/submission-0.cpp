class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int stR = row1 , lsR = row2 , stC = col1 , lsC = col2;
        int sum = 0;

        for (int i = stR ; i <= lsR; i++) {
            for (int j = stC ; j <= lsC ; j++) {
                sum = sum + this->matrix[i][j];
            }
        }

        return sum; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */