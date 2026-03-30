class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string,string> mapp;
        vector<int> dp(n+1, false);

        // empty string is always true (valid)
        dp[0] = true;

        for (auto& word : wordDict) {
            mapp[word] = word;
        }   

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string currentWord = s.substr(j,i - j); // j : i - 1
                if (mapp.count(currentWord) && dp[j]) {
                    dp[i] = true;
                }
            }
        }

        return dp[n];
    }
};
