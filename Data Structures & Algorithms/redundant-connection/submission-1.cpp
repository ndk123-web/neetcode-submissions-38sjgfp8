class Solution {
private:
    vector<int> res;
    vector<bool> visited;
    vector<vector<int>> adj;

    bool dfs(int node, int parent) {
        visited[node] = true;

        for (int& nei : adj[node]) {
            if (!visited[nei]) {
                if (dfs(nei,node)) {
                    return true;
                }
            }
            else if (nei != parent) {
                return true;    // found cycle 
            }
        }

        return false;   // cant find the cycle 
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.assign(n + 1, {});

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
            visited.assign(n + 1,false);
            if (dfs(edge[0],-1)) {
                return edge;
            }
        }    

        return {};
    }
};
