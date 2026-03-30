#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
private: 
    int target;
    vector<int> squares = vector<int>(4, 0);

    bool dfs(vector<int>& matchsticks, int idx) {
        if (idx == matchsticks.size())
            return true;

        for (int i = 0; i < 4; i++) {
            if (i > 0 && squares[i] == squares[i - 1]) continue;
            if (squares[i] + matchsticks[idx] > target) continue;

            squares[i] += matchsticks[idx];
            if (dfs(matchsticks, idx + 1))
                return true;
            squares[i] -= matchsticks[idx];
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;

        target = sum / 4;

        // very important optimization
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, 0);
    }
};
