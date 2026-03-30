class Solution {
private:
    vector<unordered_set<int>> adj, prereqMap;
    vector<int> indegree;

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pres, vector<vector<int>>& queries) {
        adj.assign(numCourses,{});    
        prereqMap.assign(numCourses,{});    
        indegree.assign(numCourses,0);    

        for (auto& pre : pres) {
            indegree[pre[1]]++;
            adj[pre[0]].insert(pre[1]);
        }

        queue<int> q;
        for (int i = 0 ; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            
            for (auto& nei : adj[node]) {
                prereqMap[nei].insert(node);
                prereqMap[nei].insert(prereqMap[node].begin(),prereqMap[node].end());
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(prereqMap[q[1]].count(q[0]));
        }

        return res;
    }
};