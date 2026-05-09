class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char, int> mp;
        queue<pair<int, int>> q;
        
        for (char t : tasks) {
            mp[t]++;
        }

        for (auto [x, y] : mp) {
            pq.push(y);
        }

        int time = 0;
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
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
