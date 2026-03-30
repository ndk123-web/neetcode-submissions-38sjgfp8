class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mapp;

        for (auto& trip : trips) {
            mapp[trip[1]] += trip[0];
            mapp[trip[2]] -= trip[0];
        }      

        int curr = 0;
        for (auto& p : mapp) {
            curr = curr + p.second;
            if (curr > capacity) return false;
        }

        return true;
    }
};