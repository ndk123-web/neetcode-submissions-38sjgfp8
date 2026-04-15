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

class MyInterval : public Interval{
    public:
        MyInterval(int a, int b) : Interval(a,b) {

        }

        bool operator<(const MyInterval& other) {
            return this->start < other.start;
        }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();

        vector<MyInterval> nintervals;
        for (int i = 0 ; i < n; i++) {
            nintervals.push_back(MyInterval(intervals[i].start, intervals[i].end));
        }

        // nlogn (use own Interval)
        sort(nintervals.begin(), nintervals.end());

        // now just need to check wrt to start of current and end of next 
        // if e < ns then its left one 
        for (int i = 0; i < n - 1; i++) {
            
            MyInterval& first = nintervals[i];
            MyInterval& second = nintervals[i + 1];

            // overlap exist 
            if (first.end > second.start) {
                return false;
            }
        }

        return true;
    }
};
