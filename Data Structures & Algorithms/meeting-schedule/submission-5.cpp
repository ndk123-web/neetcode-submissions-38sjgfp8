/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


class Solution {
public:

    // make static compare
    static bool compare(Interval& a, Interval& b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();

        // nlogn outside class compare
        sort(intervals.begin(), intervals.end(), compare);

        // now just need to check wrt to start of current and end of next 
        // if e < ns then its left one 
        for (int i = 0; i < n - 1; i++) {
            
            Interval& first = intervals[i];
            Interval& second = intervals[i + 1];

            // overlap exist 
            if (first.end > second.start) {
                return false;
            }
        }

        return true;
    }
};
