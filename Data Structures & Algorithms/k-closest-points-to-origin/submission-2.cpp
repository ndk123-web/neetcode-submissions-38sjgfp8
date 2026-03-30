class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, pair<int, int>>> pq;
        vector<vector<int>> res;

        for (auto& point : points) {
            float dist = sqrt(point[0] * point[0] + point[1] * point[1]);
            pq.push({dist, {point[0], point[1]}}); // 3. , 2.

            if (pq.size() > k) {
                pq.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            pair<int, pair<int, int>> p = pq.top();
            res.push_back({p.second.first, p.second.second});
            pq.pop();
        }

        return res;
    }
};