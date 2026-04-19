class Solution {
public:
    
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        
        return gcd(b, (a % b));
    }

    string gcdOfStrings(string s, string t) {
        string res = "";

        if (s + t != t + s) 
            return res;

        int idx = gcd(s.size(), t.size());
        return t.substr(0, idx);   
    }
};