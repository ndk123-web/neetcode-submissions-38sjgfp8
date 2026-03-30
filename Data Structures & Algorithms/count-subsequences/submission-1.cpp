class Solution {
private:
    map<pair<int,int>, int> memo;

    int dfs(string s, string t, int i, int j) {
        if (j >= t.size() && i >= s.size()) {
            return 1;
        }

        if (i >= s.size()) {
            return 0;
        }

        if (memo.find({i,j}) != memo.end()) {
            return memo[{i,j}];
        }

        // if i == j
        int cnt = 0;
        if (s[i] == t[j]) {
            // forward i,j 
            cnt = cnt + dfs(s,t,i+1,j+1);

            // forward only i 
            cnt = cnt + dfs(s,t,i+1,j);
        }

        else {
            cnt = cnt + dfs(s,t,i+1,j);
        }

        return memo[{i,j}] = cnt;
    }

public:
    int numDistinct(string s, string t) {
        return dfs(s,t,0,0);
    }
};
