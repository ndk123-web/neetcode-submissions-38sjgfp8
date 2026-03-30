class Solution {
private:
    bool res;
    unordered_map<char,int> mapp;

    bool checkStrings(string s1, string s2) {
        int i = 0, j = 0;

        while (i < s1.size() && j < s2.size()) {
            if (mapp[s1[i]] == mapp[s2[j]]) {
                i++; j++;
                continue;
            }    
            if (mapp[s1[i]] > mapp[s2[j]])
                return false;
            
            return true;
        }

        if (i != s1.size()) 
            return false;
        
        return true;
    }

    void helper(vector<string>& words) {
        for (int i = 1; i < words.size(); i++) {
            if (!checkStrings(words[i-1],words[i])) {
                res = false;
                break;
            }
        }
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        res = true;
        int cnt = 0;

        for (char& c : order) 
            mapp[c] = cnt++;

        helper(words);
        return res;
    }
};