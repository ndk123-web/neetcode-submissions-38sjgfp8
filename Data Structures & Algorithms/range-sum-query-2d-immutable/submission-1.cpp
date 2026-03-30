class NumMatrix {
private: 
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        prefixSum = vector<vector<int>>(row + 1, vector<int>(col + 1,0));

        for (int i = 1 ; i <= row ; i++) {
            for (int j = 1 ; j <= col ; j++) {
                prefixSum[i][j] = matrix[i-1][j-1] + prefixSum[i-1][j] + 
                prefixSum[i][j-1] - prefixSum[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++;
        row2++; col2++;

        int res = prefixSum[row2][col2] - prefixSum[row1-1][col2] - prefixSum[row2][col1-1] + prefixSum[row1-1][col1-1];   
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */