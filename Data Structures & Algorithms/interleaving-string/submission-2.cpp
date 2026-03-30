class Solution {
private:

    map<pair<int,int>, bool> memo; 

    bool dfs(string s1, string s2, string s3, int i, int j, int k) {
        
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }

        if (memo.find({i,j}) != memo.end()) {
            return memo[{i,j}];
        }

        bool l = false, r = false;
        if (s1[i] == s3[k]) {
            l = dfs(s1,s2,s3,i+1,j,k+1);
        }
        
        if (s2[j] == s3[k]) {
            r = dfs(s1,s2,s3,i,j+1,k+1);
        }

        return memo[{i,j}] = r || l;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if (n1 + n2 != n3) {
            return false;
        }

        return dfs(s1,s2,s3,0,0,0);
    }   
};
