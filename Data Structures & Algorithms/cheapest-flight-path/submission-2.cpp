class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<int> minStops(n, INT_MAX);
        minStops[src] = 0;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();
            if (u == dest) return cost;

            if (stops > minStops[u]) continue;
            minStops[u] = stops;

            if (stops == k + 1) continue;

            for (auto [v, wt] : adj[u]) {
                pq.push({cost + wt, v, stops + 1});
            }
        }
        return -1;
    }
};
