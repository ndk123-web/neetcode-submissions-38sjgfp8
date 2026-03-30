class Solution {
private:
    vector<bool> visited;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int totalCost = 0;
        int edgeSize = 0;
        visited.assign(n, false);

        minheap.push({0,0});

        while (edgeSize != n) {
            pair<int,int> p = minheap.top();
            minheap.pop();

            if (visited[p.second]) 
                continue;

            visited[p.second] = true;
            totalCost = totalCost + p.first;
            edgeSize++;
              
            for (int i = 0; i < n; i++) {
                // find the weights (manhattan distance)
                if (i == p.second)
                    continue;

                int dist = abs(points[p.second][0] - points[i][0]) +
                            abs(points[p.second][1] - points[i][1]);

                minheap.push({dist, i});
            }
        }

        return totalCost;
    }
};
