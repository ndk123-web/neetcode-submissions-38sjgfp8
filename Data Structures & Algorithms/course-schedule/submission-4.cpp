class Solution {
private:
    unordered_set<int> visit;
    unordered_map<int, vector<int>> mapp;

    // (0,1) (1,2) (2,0)
    // 0->1 , 1->2, 2->0 
    bool dfs(int course) {
        if (visit.find(course) != visit.end()) 
            return false;
        
        if (mapp[course].empty()) 
            return true;
        
        visit.insert(course);
        for (int& nei : mapp[course]) {
            if (!dfs(nei)) {
                return false;
            }
        }
        visit.erase(course);

        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // a is depend on b
        for (auto& pre : prerequisites) {
            mapp[pre[0]] = {};
        }
        for (auto& pre : prerequisites) {
            mapp[pre[0]].push_back(pre[1]);
        }

        for (int c = 0 ; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }

        return true;
    }
};
