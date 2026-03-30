struct TrieNode {
    bool isEnd;
    TrieNode* next[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;

    void insertWord(string& word) {
        TrieNode* curr = root;
        for (char& c : word) {
            if (curr->next[c - 'a'] == nullptr) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isEnd = true;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        root = new TrieNode();

        for (string& str : dictionary) {
            insertWord(str);
        }

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];

            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!curr->next[idx])
                    break;

                curr = curr->next[idx];
                if (curr->isEnd) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};