class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> visit;

    void dfs(int node) {
        visit[node] = true;

        for (auto& e : adj[node]) {
            if (!visit[e]) {
                dfs(e);
            }
        }

        return;
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        adj.assign(n,{});
        visit.assign(n,false);

        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0 ; i < n; i++) {
            if (!visit[i]) {
                res++;
                dfs(i); // imp 
            }
        }

        return res;
    }
};
