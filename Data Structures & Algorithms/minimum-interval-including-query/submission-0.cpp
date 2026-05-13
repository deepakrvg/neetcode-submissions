class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        int i = 0;
        vector<int> que = queries;
        sort(intervals.begin(), intervals.end());
        sort(que.begin(), que.end());
        for (int q : que) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }

            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            mp[q] = (pq.empty()) ? -1 : pq.top().first;
        }

        vector<int> ans;
        for (int q : queries) {
            ans.push_back(mp[q]);
        }

        return ans;
    }
};
