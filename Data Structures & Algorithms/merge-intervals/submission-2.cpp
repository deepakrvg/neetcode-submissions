class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (const vector<int>& interval : intervals) {
            if (!ans.empty() && interval[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
            else {
                ans.push_back(interval);
            }
        }
        return ans;
    }
};
