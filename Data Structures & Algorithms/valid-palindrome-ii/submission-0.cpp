class Solution {
public:

    bool recursion(int l , int r , int c, string s) {
        if (c > 1) return false;
        if (l >= r) return true;
        
        if (s[l] != s[r]) {
            return recursion(l+1,r,c+1,s) || recursion(l,r-1,c+1,s);
        }else {
            return recursion(l+1,r-1,c,s);
        }
    }

    bool validPalindrome(string s) {
        return recursion(0,s.size()-1,0,s);
    }
};