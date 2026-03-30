class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0) , out(n+1,0);

        for (auto& v : trust) {
            in[v[1]]++;   // accepting 
            out[v[0]]++;  // beleiving
        } 

        for (int i = 1; i <= n; i++) {
            if (in[i] == n-1 && out[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};