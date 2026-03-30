class Solution {
private:
    map<pair<int,int>, int> dp;
    int sum , target;

    int dfs(vector<int>& stones, int i, int total) {
        if (i == stones.size() || total >= target) {
            return abs(total - (sum - total));
        }

        if (dp.find({i,total}) != dp.end()) {
            return dp[{i, total}];
        }

        dp[{i,total}] = min(
            dfs(stones, i+1, total),
            dfs(stones, i+1, total + stones[i])
        );

        return dp[{i,total}];
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        sum = accumulate(stones.begin(),stones.end(),0);
        target = (sum / 2) + 1;

        return dfs(stones, 0,0);      
    }
};