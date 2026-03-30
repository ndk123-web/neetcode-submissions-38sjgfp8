class Solution {
private:
    vector<int> degree;
    vector<int> res;
    vector<vector<int>> adj;
    
    // alwaas max 2 min Height tree will be theer how ?
    // 1. odd lentgh = 1 MHT
    // 2. even length = 2 MHT 
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) 
            return {0};
        
        degree.assign(n,0);    
        adj.assign(n,{});    

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0 ; i < n ;i++) { 
            if(degree[i] == 1)
                q.push(i);
        }

        int remain = n;

        while (remain > 2) {
            int size = q.size();
            remain = remain - size;

            for (int i = 0 ; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int& nei : adj[node]) {
                    if (--degree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};