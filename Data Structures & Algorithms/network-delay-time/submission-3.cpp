class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> mat(n+1, vector<int>(n+1, 1001));

        for (vector<int>& time : times) {
            mat[time[0]][time[1]] = time[2];
        }
        for (int i = 1; i <= n; i++) {
            mat[i][i] = 0;
        }

        for (int k = 1 ; k <= n ; k++) {
            for (int i = 1 ; i <= n; i++) {
                for (int j = 1 ; j <= n; j++) {
                    if (mat[i][k] != 1001 && mat[k][j] != 1001)
                        mat[i][j] = min(mat[i][j], (mat[i][k] + mat[k][j]));           
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (mat[k][i] == 1001) 
                return -1;
            res = max(res, mat[k][i]);
        }

        return res;        
    }
};
