struct TrieNode {
    char ch;
    vector<TrieNode*> others;
    bool isEnd;

    TrieNode(char ch) {
        this->ch = ch;
        isEnd = false;
        others.resize(26, nullptr);
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, TrieNode* node, int idx) {

        if (idx == word.size()) {
            return node->isEnd;
        }

        char ch = word[idx];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->others[i] != nullptr) {
                    if (dfs(word,node->others[i],idx+1)) 
                        return true;
                }
            }
            return false;
        }

        else {
            if (node->others[ch-'a'] == nullptr)
                return false;
            
            return dfs(word,node->others[ch-'a'],idx+1);
        }
    }

public:
    WordDictionary() { root = new TrieNode('r'); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char& c : word) {
            if (curr->others[c - 'a'] == nullptr) {
                curr->others[c - 'a'] = new TrieNode(c);
            }
            curr = curr->others[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(word, root, 0); }
};