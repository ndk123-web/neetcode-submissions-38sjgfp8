class Solution {
private:
    vector<vector<int>> mapp;
    vector<bool> visited;

    bool dfs(int node, int parent) {
        visited[node] = true;

        for (auto& nei : mapp[node]) {
            if (!visited[nei]) {
                if (!dfs(nei,node))
                    return false;
            }
            else if (nei != parent)
                return false;
        }   

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        mapp.assign(n,{});
        visited.assign(n,false);

        for (auto& edge : edges) {
            mapp[edge[0]].push_back(edge[1]);
            mapp[edge[1]].push_back(edge[0]);
        }

        // if cycle exists
        if (!dfs(0,-1)) 
            return false;
        
        // if no connectivity
        for (bool visit : visited) {
            if (!visit)
                return false;
        }

        return true;
    }
};
