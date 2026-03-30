class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int left = 0, right = ROWS * COLS - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / COLS, c = mid % COLS;

            if (matrix[r][c] < target) {
                left = mid + 1;
            }

            else if (matrix[r][c] > target) {
                right = mid - 1;
            }

            else {
                return true;
            }
        }

        return false;
    }
};