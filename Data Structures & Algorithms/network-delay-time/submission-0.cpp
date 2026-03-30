class Solution {
private:
    vector<bool> visited;
    unordered_map<int, vector<pair<int,int>>> adj;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        visited.assign(n, false);
        int minVal = 0;
        int count = 0;

        for (vector<int>& time : times) {

            // 0 based 
            adj[time[0]-1].push_back({time[2],time[1]-1});
        }

        // 0 based
        pq.push({0,k-1});    

        while (!pq.empty()) {
            if (count == n)
                break;

            pair<int,int> mnp = pq.top();
            pq.pop();

            if (visited[mnp.second]) {
                continue;
            }

            visited[mnp.second] = true;

            minVal = mnp.first;
            count++;

            for (pair<int,int>& p : adj[mnp.second]) {
                pq.push({mnp.first+p.first, p.second});
            }
        }

        return count == n ? minVal : -1;
    }
};