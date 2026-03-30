struct TrieNode {
    char c;
    vector<TrieNode*> others;
    bool isEnd;

    TrieNode(char newchar) {
        c = newchar;
        others.resize(26,nullptr);
        isEnd = false;
    }
};

class PrefixTree {
private:
    TrieNode* root = nullptr;

public:
    PrefixTree() {
        root = new TrieNode('r');
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char& c : word) {
            int idx = c - 'a';

            if (curr->others[idx] == nullptr) {
                curr->others[idx] = new TrieNode(c);
            }
            curr = curr->others[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char& c : word) {
            int idx = c - 'a';
            if (curr->others[idx] == nullptr) return false;
            curr = curr->others[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char& c : prefix) {
            if (curr->others[c-'a'] == nullptr) return false;
            curr = curr->others[c-'a'];
        }   
        return true;
    }
};
