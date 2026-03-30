class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        int i = 0;
        long long time = tasks[0][0];
        while (!minHeap.empty() || i < n) {
            while (i < n && time >= tasks[i][0]) {
                minHeap.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if (minHeap.empty()) {
                time = tasks[i][0];
            } else {
                auto p = minHeap.top();
                minHeap.pop();
                time += p.first;
                res.push_back(p.second);
            }
        }
        return res;
    }
};