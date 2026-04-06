class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int total = 0;
        int start = 0;
        int n = gas.size();

        // -1 0 -1 3


        vector<int> diff(n, 0);
        for (int i = 0; i < n; i++) {
            diff[i] = gas[i] - cost[i];
        }

        // start = 1
        // total = -1 + 0 = -1 - 1 = -2 + 3 = 1  
        // tank = 3
        for (int i = 0; i < n; i++) {
            tank += diff[i];
            total += diff[i];

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }   

        return total >= 0 ? start : -1;     
    }
};
