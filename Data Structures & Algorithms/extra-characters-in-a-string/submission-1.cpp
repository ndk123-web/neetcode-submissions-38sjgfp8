struct TrieNode {
    TrieNode* next[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0 ; i < 26; i++) next[i] = nullptr;
    }
};


class Solution {
private:
    TrieNode* root;

    void insertStr(string& s) {
        TrieNode* curr = root;
        for (char& c : s) {
            if (curr->next[c-'a'] == nullptr) {
                curr->next[c-'a'] = new TrieNode();
            }
            curr = curr->next[c-'a'];
        }

        curr->isEnd = true;
    }

public:
int minExtraChar(string s, vector<string>& dictionary) {
        root = new TrieNode();

        // Build Trie
        for (auto& word : dictionary)
            insertStr(word);

        int n = s.size();
        vector<int> dp(n + 1, 0);

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: treat s[i] as extra char
            dp[i] = 1 + dp[i + 1];

            // Option 2: try matching dictionary words
            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!curr->next[idx]) break;

                curr = curr->next[idx];
                if (curr->isEnd) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};