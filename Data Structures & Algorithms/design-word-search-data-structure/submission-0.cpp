struct TrieNode {
    char ch;
    vector<TrieNode*> others;
    bool isEnd;

    TrieNode(char ch) {
        this->ch = ch;
        isEnd = false;
        others.resize(26,nullptr);
    }
};

class WordDictionary {
private:    
    TrieNode* root;

    bool dfs(string& word, int idx, TrieNode* node) {
    if (idx == word.size())
        return node->isEnd;

    char c = word[idx];

    if (c == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->others[i] != nullptr) {
                if (dfs(word, idx + 1, node->others[i]))
                    return true;
            }
        }
        return false;
    } else {
        int pos = c - 'a';
        if (node->others[pos] == nullptr)
            return false;
        return dfs(word, idx + 1, node->others[pos]);
    }
}

    
public:
    WordDictionary() {
        root = new TrieNode('r');   
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char& c : word) {
            if (curr->others[c-'a'] == nullptr) {
                curr->others[c-'a'] = new TrieNode(c);
            }
            curr = curr->others[c-'a'];
        }   
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
