class Solution {
   public:
    int romanToInt(string s) {
        /*
                Symbol       Value
                I             1
                V             5
                X             10
                L             50
                C             100
                D             500
                M             1000
        */
        unordered_map<char, int> mapp;
        mapp['I'] = 1;
        mapp['V'] = 5;
        mapp['X'] = 10;
        mapp['L'] = 50;
        mapp['C'] = 100;
        mapp['D'] = 500;
        mapp['M'] = 1000;

        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mapp[s[i]] < mapp[s[i + 1]]) {
                total -= mapp[s[i]];
            } else {
                total += mapp[s[i]];
            }
        }

        return total;
    }
};