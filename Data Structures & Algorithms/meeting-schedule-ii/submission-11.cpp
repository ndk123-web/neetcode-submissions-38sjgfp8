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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) 
            return 0;   

        // sort by start time 
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(intervals[0].end);

        // max required 1 room
        int rooms = 1;
        for (int i = 1; i < n; i++) {

            while (!pq.empty() && pq.top() <= intervals[i].start){
                pq.pop();
            }

            pq.push(intervals[i].end);
            rooms = max(rooms, (int)pq.size());
        }

        return rooms;
    }
};
