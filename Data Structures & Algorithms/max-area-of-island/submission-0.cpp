class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m) {
            return 0;
        }
        if (grid[r][c] == 0 || vis[r][c] == true) {
            return 0;
        }

        int ans = 1;
        vis[r][c] = true;
        ans += dfs(grid, vis, r + 1, c);
        ans += dfs(grid, vis, r - 1, c);
        ans += dfs(grid, vis, r, c + 1);
        ans += dfs(grid, vis, r, c - 1);
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};
