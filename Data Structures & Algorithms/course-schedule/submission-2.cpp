class Solution {
private:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> mapp;

    bool dfs(int course) {
        if (visited.count(course)) {
            return false;
        }

        if (mapp[course].empty()) {
            return true;
        }

        visited.insert(course);
        for (int& co : mapp[course]) {
            if (!dfs(co)) {
                return false;
            }
        }
        visited.erase(course);

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0 ; i < numCourses; i++) {
            mapp[i] = {};
        }    

        for (auto& pre : prerequisites) {
            mapp[pre[0]].push_back(pre[1]);
        }

        for (int i = 0 ; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }

        return true;
    }
};
