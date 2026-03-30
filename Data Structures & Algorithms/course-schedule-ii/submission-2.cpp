class Solution {
private:
    vector<int> res;
    unordered_map<int,vector<int>> mapp;
    unordered_set<int> visit;
    
    bool dfs(int course) {
        if (visit.find(course) != visit.end()) {
            return false;
        }

        if (mapp[course].empty()) {
            if (find(res.begin(),res.end(),course) == res.end()) {
                res.push_back(course);
            }
            return true;
        }

        visit.insert(course);
        for (int& nei : mapp[course]) {
            if (!dfs(nei)) {
                return false;
            }
        }
        visit.erase(course);
            if (find(res.begin(),res.end(),course) == res.end()) {
                res.push_back(course);
            }

        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        res = {};

        for (vector<int>& pre : prerequisites) {
            mapp[pre[0]] = {};
        }

        for (vector<int>& pre : prerequisites) {
            mapp[pre[0]].push_back(pre[1]);
        }

        for (int i = 0 ; i < numCourses; i++) {
            if (!dfs(i)) {
                return {};
            }
        }

        for (int i = 0 ; i < numCourses; i++) {
            if (find(res.begin(),res.end(),i) == res.end()) {
                res.push_back(i);
            }
        }

        return res;
    }
};
