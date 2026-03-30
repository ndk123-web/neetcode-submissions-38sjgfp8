class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n+1, 0);

        // asusme for 1 we have max product 1
        dp[1] = 1;        

        for (int i = 2; i <= n; i++)  {
            dp[i] = (i == n) ? 0 : i; 
            // assume i = 3 
            // now either j = 1 , i-j = 2 (that can build 3 as sum and product will be dp[j]* dp[i-j])
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
            }
        }

        return dp[n];
    }
};