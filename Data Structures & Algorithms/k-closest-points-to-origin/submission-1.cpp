class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        vector<vector<int>> res;

        for (auto& point : points) {
            int dist = pow(point[0],2) + pow(point[1],2);
            pq.push({dist,point});
        }

        for (int i = 0 ; i < k; i++) {
            pair<int,vector<int>> p = pq.top();
            res.push_back(p.second);
            pq.pop();
        }

        return res;
    }
};