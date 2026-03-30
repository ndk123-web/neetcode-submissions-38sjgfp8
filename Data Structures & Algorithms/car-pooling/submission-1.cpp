class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](auto& a, auto& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int curr = 0;
        for (auto& trip : trips) {
            int pass = trip[0] , from = trip[1] , to = trip[2];

            while (!pq.empty() && pq.top().first <= from) {
                curr = curr - pq.top().second;
                pq.pop();
            }

            curr = curr + pass;

            if (curr > capacity) return false;
            pq.push({to,pass});
        }

        return true;
    }
};