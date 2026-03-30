class Solution {
private:


    // adjacency map (string -> minheap)
    unordered_map<string, vector<string>> adj;

    // result
    vector<string> res;

    void dfs(string node) {
        while (!adj[node].empty()) {
            // most lexicographically small string
            string next = adj[node].front();

            // pop the edge
            adj[node].erase(adj[node].begin());

            // go for next edge
            dfs(next);
        }

        res.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        // 1. adjacency list (create DAG) 
        for (vector<string>& str : tickets) {
            adj[str[0]].push_back(str[1]);
        }

        for (vector<string>& str : tickets) {
            sort(adj[str[0]].begin(), adj[str[0]].end());
        }
        
        string start = "JFK";
        // res.push_back(star)
        dfs(start);

        reverse(res.begin(),res.end());
        return res;       
    }
};
