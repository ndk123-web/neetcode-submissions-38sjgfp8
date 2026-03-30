class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n + 1];   

        for (int i = 0 ; i < n; i++) {
            dp[i] = 0;
        }

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                continue;
            }
            // check first digit
            dp[i] = dp[i+1];

            if (i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i+2]; // include i,i+1 now include total possibility of i + 2
                }
            }
        }

        return dp[0];
    }
};
