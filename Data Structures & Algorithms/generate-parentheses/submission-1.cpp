class Solution {
private:    
    vector<string> res;

    void dfs(int open, int close, int n, string part) {

        if (part.size() == 2*n) {
            res.push_back(part);
            return;
        }

        // 0 0 
        // 1 0 ( -> , 2 0 -> (( , 3 0 -> (((, 
        if (open < n) {
            dfs(open+1,close,n,part+"(");
        } 

        if (close < open) {
            dfs(open,close+1,n,part+")");
        }

        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n,"");
        return res;
    }
};
