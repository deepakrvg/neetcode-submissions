class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // vector<vector<pair<int, int>>> adj;
        int n = points.size();
        int ans = 0;
        vector<int> vis(n, 0);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        for (int step = 0; step < n; step++) {
            // find unvisited node with min distance
            int node = -1;
            int minDist = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && dist[i] < minDist) {
                    node = i;
                    minDist = dist[i];
                }
            }

            vis[node] = 1;
            ans += minDist;

            for (int j = 0; j < n; j++) {
                int x1 = points[node][0];
                int y1 = points[node][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (!vis[j]) {
                    int len = abs(x1 - x2) + abs(y1 - y2);
                    dist[j] = min(dist[j], len);
                }
            }
        }
        return ans;
    }
};
