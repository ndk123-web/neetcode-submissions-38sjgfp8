class Solution {
private:
    unordered_set<int> visit;
    unordered_set<int> seen;
    vector<int> order;
    vector<int> res;
    unordered_map<int,vector<int>> mapp;

    bool dfs(int course) {
        if (visit.count(course)) 
            return false;
        
        if (mapp[course].empty()) {
            if (!seen.count(course)) {
            seen.insert(course);
            order.push_back(course);
            }
            return true;
        }
        
        visit.insert(course);
        for(auto& nei : mapp[course]) {
            if (!dfs(nei))
                return false;
        }
        visit.erase(course);

        if (!seen.count(course)) {
            seen.insert(course);
            order.push_back(course);
        }

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pres) {
        for (auto& pre : pres) {
            mapp[pre[0]] = {};
        }

        for (auto& pre : pres) {
            mapp[pre[0]].push_back(pre[1]);
        }

        for (int i = 0 ; i < numCourses; i++) {
            if (!dfs(i)){
                return {};
            }
        }

        for (int i = 0 ; i < order.size(); i++) {
            res.push_back(order[i]);
        }

        return res;
    }
};