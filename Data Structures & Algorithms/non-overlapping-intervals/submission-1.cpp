class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> last;
        int count = 0;
        for (const vector<int>& interval : intervals) {
            if (!last.empty() && last[1] > interval[0]) {
                count++;
                last[1] = min(last[1], interval[1]);
            }
            else {
                last = interval;
            }
            cout << last[0] << " " << last[1] << endl;
        }
        return count;
    }
};
