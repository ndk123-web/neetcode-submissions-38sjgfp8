class Solution {
private:
    vector<bool> visited;
    unordered_map<int, vector<int>> adj;
    int res;

    void dfs(int node) {
        visited[node] = true;

        for (auto& nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei);
            }
        }

        return;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        res = 0;
        visited.assign(n,false);

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
 
        for (int i = 0 ; i < n ; i++) {
            if (!visited[i]){
                res++;
                dfs(i);
            }
        }

        return res;
    }
};
