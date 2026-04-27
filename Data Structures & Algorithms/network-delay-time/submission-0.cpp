class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n + 1, INF);
        dist[k] = 0;
        dist[0] = 0;
        while (!pq.empty()) {
            auto [dt, u] = pq.top();
            pq.pop();
            for (auto [v, d] : adj[u]) {
                if (dist[v] > dist[u] + d) {
                    dist[v] = dist[u] + d;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = -1;
        for (int x : dist) {
            if (x == INF) return -1;
            ans = max(ans, x);
        }
        return ans;
    }
};
