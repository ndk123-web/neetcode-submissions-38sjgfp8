class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> mapp;

    bool dfs(int node, int parent) {
        visited[node] = true;

        for (auto& e : mapp[node]) {
            if (!visited[e]) {
                if (!dfs(e,node)) {
                    return false;
                }
            }
            else if (e != parent) {
                return false;
            }
        }

        return true;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Graph Valid 
        // 1. No Cycle Exists
        // 2. Exactly N-1 Edges 
        // 3. all nodes must be reachable from any node
        visited.assign(n,false);
        mapp.assign(n,{});

        for (auto& e : edges) {
            mapp[e[0]].push_back(e[1]);
            mapp[e[1]].push_back(e[0]);
        }

        if (!dfs(0,-1)) 
            return false;
        
        for (bool v : visited){
            if (!v) 
                return false;
        }

        return true;
    }
};
