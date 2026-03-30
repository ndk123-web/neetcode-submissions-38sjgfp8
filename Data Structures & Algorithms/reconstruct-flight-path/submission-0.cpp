class Solution {
private:


    // adjacency map (string -> minheap)
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;

    // result
    vector<string> res;

    void dfs(string node) {
        while (!adj[node].empty()) {
            // most lexicographically small string
            string next = adj[node].top();

            // pop the edge
            adj[node].pop();

            // go for next edge
            dfs(next);
        }

        res.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        // 1. adjacency list (create DAG) 
        for (vector<string>& str : tickets) {
            adj[str[0]].push(str[1]);
        }
        
        string start = "JFK";
        // res.push_back(star)
        dfs(start);

        reverse(res.begin(),res.end());
        return res;       
    }
};
