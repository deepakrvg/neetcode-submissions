class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            if ((row + dx[i] < n && row + dx[i] >= 0 && col + dy[i] < m && col + dy[i] >= 0) && !vis[row + dx[i]][col + dy[i]] && grid[row + dx[i]][col + dy[i]] == '1') {
                dfs(grid, vis, row + dx[i], col + dy[i]);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return ans;
    }
};
