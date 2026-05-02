class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [wt, x, y] = pq.top();
            pq.pop();

            if (x > 0 && dist[x - 1][y] > dist[x][y] + grid[x - 1][y]) {
                dist[x - 1][y] = max(dist[x][y], grid[x - 1][y]);
                pq.push({dist[x - 1][y], x - 1, y});
            }
            if (x < n - 1 && dist[x + 1][y] > dist[x][y] + grid[x + 1][y]) {
                dist[x + 1][y] = max(dist[x][y], grid[x + 1][y]);
                pq.push({dist[x + 1][y], x + 1, y});
            }
            if (y > 0 && dist[x][y - 1] > dist[x][y] + grid[x][y - 1]) {
                dist[x][y - 1] = max(dist[x][y], grid[x][y - 1]);
                pq.push({dist[x][y - 1], x, y - 1});
            }
            if (y < n - 1 && dist[x][y + 1] > dist[x][y] + grid[x][y + 1]) {
                dist[x][y + 1] = max(dist[x][y], grid[x][y + 1]);
                pq.push({dist[x][y + 1], x, y + 1});
            }

            if (x == n - 1 && y == n - 1) {
                return dist[n - 1][n - 1];
            }
        }
        return dist[n - 1][n - 1];
    }
};
