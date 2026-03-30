class Solution {
private:
    unordered_map<int, vector<int>> adj;

    int dfs(int node, int parent) {
        int maxHeight = 0;

        for (int& nei : adj[node]) {
            if (nei == parent) continue;

            int depth = dfs(nei,node);
            maxHeight = max(maxHeight, depth);
        }

        return maxHeight + 1;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> res;
        int minHeight = INT_MAX;

        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0 ; i < n; i++) {
            int h = dfs(i,-1) - 1;
            minHeight = min(minHeight,h);
            res.push_back({h, i});
        }

        vector<int> newRes;
        for (auto& p : res) {
            if (minHeight == p.first)
                newRes.push_back(p.second);
        }

        return newRes;
    }       
};