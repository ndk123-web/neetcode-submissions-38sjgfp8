class Solution {
   private:
    vector<int> res;

    void dfs(vector<vector<int>>& matrix, int top, int bottom, int left, int right) {
        if (left > right || top > bottom) return;

        for (int i = left; i <= right; i++) {
            res.push_back(matrix[top][i]);
        }
        top++;

        if (left > right || top > bottom) return;
        for (int i = top; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        right--;

        if (left > right || top > bottom) return;
        for (int i = right; i >= left; i--) {
            res.push_back(matrix[bottom][i]);
        }
        bottom--;

        if (left > right || top > bottom) return;
        for (int i = bottom; i >= top; i--) {
            res.push_back(matrix[i][left]);
        }
        left++;

        dfs(matrix, top, bottom, left, right);
        return;
    }

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        dfs(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
        return res;
    }
};