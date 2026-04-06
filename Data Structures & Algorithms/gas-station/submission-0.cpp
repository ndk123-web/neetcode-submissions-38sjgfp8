class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // brute force 
        // start from 0 to n - 1
        // check if tank >= 0 means continue 
        // check if tank < 0 take another i else return -1

        int n = gas.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            int curr = i;
            int tank = 0;
            int cnt = 0;

            while (visited.size() < n) {
                curr = curr % n;
                tank = tank + gas[curr] - cost[curr];

                if (tank < 0) {
                    break;
                }

                visited.insert((curr % n));
                curr++;
                cnt++;
            } 

            if (cnt == n) return i;
        }

        // 1 2 3 4
        // 2 2 4 1

        // visited = 3 0 1 
        // curr = 0
        // tank = 2 

        return -1; 
    }
};
