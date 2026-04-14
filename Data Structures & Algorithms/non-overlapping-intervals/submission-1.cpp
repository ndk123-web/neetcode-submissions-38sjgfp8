class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int minRequired = 0;

        // sort it
        sort(intervals.begin(), intervals.end());

        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            
            // if overlap then attach lastEnd as min of lastEnd and current interval end 
            if (lastEnd > intervals[i][0]) {
                lastEnd = min(lastEnd, intervals[i][1]);
                minRequired++;
            }
            // no overlap
            else {
                lastEnd = intervals[i][1];
            }
        }

        return minRequired;
    }
};
