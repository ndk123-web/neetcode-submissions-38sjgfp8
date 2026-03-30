class Solution {
private:
    map<pair<int,int>, int> memo;

    int dfs(int i, int j, string word1, string word2) {

        if (i >= word1.size()) {
            return word2.size() - j;
        }

        if (j >= word2.size()) {
            return word1.size() - i;
        }

        if (memo.find({i,j}) != memo.end()) {
            return memo[{i,j}];
        }

        if (word1[i] == word2[j]) {
            return dfs(i+1, j+1, word1, word2);
        }

        else {
            int res = INT_MAX;
            int replace = dfs(i+1,j+1,word1,word2);
            int insert  = dfs(i, j+1, word1, word2);
            int remove = dfs(i+1, j, word1, word2);

            return memo[{i,j}] = 1 + min({replace, insert, remove});
        }
    }
public:
    int minDistance(string word1, string word2) {
        return dfs(0,0,word1, word2);    
    }
};
