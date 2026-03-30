class Solution {
private:
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    vector<vector<pair<int,int>>> adj;
    vector<bool> visited;

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        visited.assign(n,false);
        adj.assign(n,{});
        
        int maxAns = -1;
        int cnt = 0;

        // store edges in adj 
        for (vector<int>& time : times) {
            adj[time[0]-1].push_back({time[2], time[1]-1});
        }    

        minheap.push({0,k-1});
        while (!minheap.empty()) {
            if (cnt == n)
                break;

            pair<int,int> p = minheap.top();
            minheap.pop();

            if (visited[p.second]) {
                continue;
            }
            maxAns = p.first;
            visited[p.second] = true;
            cnt++;

            for (auto& nei : adj[p.second]) {
                minheap.push({p.first + nei.first, nei.second});
            }
        }

        return cnt == n ? maxAns : -1;
    }
};
