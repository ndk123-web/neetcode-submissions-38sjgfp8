class Solution {
private:

    // abc
    // 1. abc
    int expand(string&s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        
        for (int i = 0 ; i < n; i++) {
            res+= expand(s,i,i);
            res+= expand(s,i,i+1);
        }

        return res;
    }
};
