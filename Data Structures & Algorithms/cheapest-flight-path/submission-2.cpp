class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> adj;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> minStops(n, INT_MAX);

        // adj == (src , (dest, cost) )
        for (vector<int>& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // 0 cost , (src, stopsUsed)
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();

            int cost = p.first;
            int node = p.second.first;
            int stops = p.second.second;

            if (node == dst) {
                return cost;
            }

            if (stops > k + 1 || stops > minStops[node]) {
                continue;
            }

            minStops[node] = stops;

            for (pair<int, int>& nei : adj[node]) {
                int tcost = cost;
                int tstops = stops;

                tcost = tcost + nei.second;
                tstops = tstops + 1;

                if (tstops <= k + 1) {
                    pq.push({tcost, {nei.first, tstops}});
                }
            }
        }

        return minStops[dst] == INT_MAX ? -1 : minStops[dst];
    }
};