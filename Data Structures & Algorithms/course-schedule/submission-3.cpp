class Solution {
private:
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // dependacy list
        vector<int> indegree(numCourses,0);     // independant list 
        queue<int> q;
        int finish = 0;

        for (auto& pre : prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }    

        for (int i = 0 ; i < numCourses; i++) {
            if (indegree[i] == 0) 
                q.push(i);
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            finish++;

            for (int& nei : adj[course]) {
                indegree[nei]--;
                if (indegree[nei] == 0) 
                    q.push(nei);
            }
        }

        return numCourses == finish;
    }
};
