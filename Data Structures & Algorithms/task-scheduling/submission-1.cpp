class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int time = 0;
        for (int t : tasks) {
            mp[t]++;
        }
        for (auto [k, v] : mp) {
            pq.push(v);
        }

        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0) {
                    q.push({freq, time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                int f = q.front().first;
                pq.push(f);
                q.pop();
            }
        }
        return time;
    }
};
