class Solution {
public:
    int numDistinct(string s, string t) {
        int r = s.size();
        int c = t.size();

        vector<vector<long long>> dp(r + 1, vector<long long>(c + 1, 0));

        // if j finished means 1 way 
        for (int i = 0; i <= r; i++) {
            dp[i][c] = 1;
        }

        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
};