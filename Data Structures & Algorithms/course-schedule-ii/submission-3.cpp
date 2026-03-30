class Solution {
private:
    vector<vector<int>> adj;
    vector<int> indegree;
    vector<int> res;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pres) {
        indegree.assign(numCourses,0);      // before 
        adj.assign(numCourses,{}); // 0-> {} course before after mapping 
        queue<int> q;

        for (auto& pre : pres) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }    

        for (int i = 0 ; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (auto& nei : adj[course]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
            res.push_back(course);
        }

        if (res.size() != numCourses) return {};
        return res;
    }
};
