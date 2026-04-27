class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x > 0 && grid[x - 1][y] == 1 && dist[x - 1][y] == -1) {
                dist[x - 1][y] = dist[x][y] + 1;
                q.push({x - 1, y});
            }
            if (x < n - 1 && grid[x + 1][y] == 1 && dist[x + 1][y] == -1) {
                dist[x + 1][y] = dist[x][y] + 1;
                q.push({x + 1, y});
            }
            if (y > 0 && grid[x][y - 1] == 1 && dist[x][y - 1] == -1) {
                dist[x][y - 1] = dist[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y < m - 1 && grid[x][y + 1] == 1 && dist[x][y + 1] == -1) {
                dist[x][y + 1] = dist[x][y] + 1;
                q.push({x, y + 1});
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dist[i][j]);
                if (dist[i][j] == -1 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
