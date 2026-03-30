class Solution {
private:
    vector<vector<int>> memo;
    vector<int> suffix;

    int dfs(int i, int M, vector<int>& piles) {
        int n = piles.size();

        if (i >= n) return 0;

        if (memo[i][M] != -1) return memo[i][M];

        int maxStones = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = dfs(i + X, max(M, X), piles);
            int current = suffix[i] - opponent;

            maxStones = max(maxStones, current);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        memo.assign(n, vector<int>(n + 1, -1));
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        return dfs(0, 1, piles);
    }
};