class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x != 0 && grid[x - 1][y] > grid[x][y] + 1 && grid[x - 1][y] != -1) {
                grid[x - 1][y] = grid[x][y] + 1;
                q.push({x - 1, y});
            }
            if (x != n - 1 && grid[x + 1][y] > grid[x][y] + 1 && grid[x + 1][y] != -1) {
                grid[x + 1][y] = grid[x][y] + 1;
                q.push({x + 1, y});
            }
            if (y != 0 && grid[x][y - 1] > grid[x][y] + 1 && grid[x][y - 1] != -1) {
                grid[x][y - 1] = grid[x][y] + 1;
                q.push({x, y - 1});
            }
            if (y != m - 1 && grid[x][y + 1] > grid[x][y] + 1 && grid[x][y + 1] != -1) {
                grid[x][y + 1] = grid[x][y] + 1;
                q.push({x, y + 1});
            }
        }
    }
};
