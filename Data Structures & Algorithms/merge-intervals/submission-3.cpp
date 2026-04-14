class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        // sort them so (0th element always less than next one)
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);    

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = res.back();
            vector<int> curr = intervals[i];

            if (last[1] < curr[0]) {
                res.push_back(curr);
            }
            else {
                last[1] = max(last[1], curr[1]);
            }
        }   

        return res;
    }
};
