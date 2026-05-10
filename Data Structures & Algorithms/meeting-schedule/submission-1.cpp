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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        Interval* last = NULL;
        for (Interval& interval : intervals) {
            if (last && interval.start < last->end) {
                return false;
            }
            else {
                last = &interval;
            }
        }
        return true;
    }
};
