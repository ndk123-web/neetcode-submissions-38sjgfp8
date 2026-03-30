class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);

        // to build 0 we need 0 digit so count = 0 
        dp[0] = 0;  

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= i; j++) {
                
                int sq = j*j;
                if (j*j <= i) {
                    dp[i] = min(dp[i], 1 + dp[i-sq]);
                }
            }
        }

        return dp[n];
    }
};