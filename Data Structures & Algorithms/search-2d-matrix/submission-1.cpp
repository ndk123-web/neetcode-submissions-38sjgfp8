class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int i = 0;
        while (i < r) {
            int l = 0 , r = c - 1;
            while (l <= r) {
                int m = l + (r-l)/2;
                if (matrix[i][m] < target) {
                    l = m + 1;
                }
                else if (matrix[i][m] > target) {
                    r = m - 1;
                } 
                else {
                    return true;
                }
            }
            i++;
        }

        return false;
    }
};
