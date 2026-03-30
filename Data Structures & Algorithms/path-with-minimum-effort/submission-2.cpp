class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int rows = heights.size() , cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> dirs = { {0,1} , {0,-1} , {1,0} , {-1,0} };

        pq.push({0, {0,0}});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int currEffort = p.first;
            int r = p.second.first;
            int c = p.second.second;

            if (r == rows - 1 && c == cols - 1) {
                return currEffort;
            }

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(diff,currEffort);

                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};