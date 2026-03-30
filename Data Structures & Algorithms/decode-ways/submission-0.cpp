class Solution {
private:
    unordered_map<int,int> memo;

    int dfs(string& s , int i) {
        
        // means we reached the end so return 1 that we found 1 way
        if (i >= s.size()) {
            return 1;
        }

        // if it is 0 then return 0 means from here there is no path
        if (s[i] == '0') {
            return 0;
        }

        if (memo.count(i)) {
            return memo[i];
        }

        // include current and jump to index i + 1
        int ways = dfs(s, i+1);

        if (i + 1  < s.size()) {

            // if "26" then 2*10 + 6 = 26 in integer
            int num = (s[i] - '0')*10 + (s[i+1] - '0');

            // minimum 2 digit number would be between 10 to 26
            if (num >= 10 && num <= 26) {
                // include index 1 and jump to index i + 2
                ways += dfs(s,i+2);
            }
        }

        memo[i] = ways;
        return ways;
    }

public:
    int numDecodings(string s) {
        return dfs(s,0);
    }
};
