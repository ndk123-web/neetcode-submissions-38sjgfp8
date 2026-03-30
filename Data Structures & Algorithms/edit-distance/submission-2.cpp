class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = word1.size();
        int c = word2.size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, INT_MAX));

        // to delete if word 2 empty or increase to the boundary
        for (int i = 0; i <= r; i++) {
            dp[i][c] = r - i;
        }

        for (int i = 0 ; i <= c; i++) {
            dp[r][i] = c - i;
        }

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c-1; j>= 0; j--) {
                if (word1[i] != word2[j]) {
                    dp[i][j] = 1 + min({
                        dp[i+1][j+1],
                        dp[i+1][j],
                        dp[i][j+1]
                    });
                }
                else {
                    dp[i][j] = dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
};
