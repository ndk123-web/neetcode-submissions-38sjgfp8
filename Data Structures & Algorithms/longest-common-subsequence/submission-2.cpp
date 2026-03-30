class Solution {
private:
    vector<vector<int>> dp;
    int dfs(string a, string b, int idxa, int idxb) {
        if (idxa == a.size() || idxb == b.size()) {
            return 0;
        }


        if (a[idxa] == b[idxb]) {
            return 1 + dfs(a,b,idxa+1, idxb+1);
        }
        
        if (dp[idxa][idxb] != 0) {
            return dp[idxa][idxb];
        }

        return dp[idxa][idxb] = max(
            dfs(a,b,idxa+1,idxb),
            dfs(a,b,idxa, idxb+1)
        );
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), 0));

        return dfs(text1,text2,0,0);
    }
};
