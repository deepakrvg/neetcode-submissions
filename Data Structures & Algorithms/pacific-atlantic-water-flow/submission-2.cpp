class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int x, int y, int val) {
        int n = heights.size();
        int m = heights[0].size();
        if (x < 0 || y < 0 || x >= n || y >= m) {
            return;
        }

        vis[x][y] += val;
        if (x > 0 && heights[x - 1][y] >= heights[x][y] && vis[x - 1][y] != val && vis[x - 1][y] != 3) {
            dfs(heights, vis, x - 1, y, val);
        }
        if (x < n - 1 && heights[x + 1][y] >= heights[x][y] && vis[x + 1][y] != val && vis[x + 1][y] != 3) {
            dfs(heights, vis, x + 1, y, val);
        }
        if (y > 0 && heights[x][y - 1] >= heights[x][y] && vis[x][y - 1] != val && vis[x][y - 1] != 3) {
            dfs(heights, vis, x, y - 1, val);
        }
        if (y < m - 1 && heights[x][y + 1] >= heights[x][y] && vis[x][y + 1] != val && vis[x][y + 1] != 3) {
            dfs(heights, vis, x, y + 1, val);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            if (vis[i][0] == 0 || vis[i][0] == 2) {
                dfs(heights, vis, i, 0, 1);
            }
            if (vis[i][m - 1] == 0 || vis[i][m - 1] == 1) {
                dfs(heights, vis, i, m - 1, 2);
            }
        }

        for (int j = 0; j < m; j++) {
            if (vis[0][j] == 0 || vis[0][j] == 2) {
                dfs(heights, vis, 0, j, 1);
            }
            if (vis[n - 1][j] == 0 || vis[n - 1][j] == 1) {
                dfs(heights, vis, n - 1, j, 2);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
