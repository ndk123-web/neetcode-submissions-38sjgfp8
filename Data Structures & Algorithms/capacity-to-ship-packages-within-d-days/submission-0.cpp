class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int res = *max_element(weights.begin(),weights.end());

        while (true) {
            
            int cap = res;
            int ships = 1;
            
            for (auto& w : weights) {
                if (cap - w < 0) {
                    ships++;
                    cap = res;
                }
                cap = cap - w;
            }

            if (ships <= days) return res;
            res++;
        }

        return res;
    }
};