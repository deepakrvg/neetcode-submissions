class Solution {
public:
    int rec(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp) {
        // base case
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size()) {
            return 0;
        }

        // dp state check
        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        // if (matrix[x][y] > par) {
        //     dp[x][y] = count + 1;
        // }
        // recurrence relation
        // rec(matrix, x + 1, y, matrix[x][y], dp[x][y], dp);
        // rec(matrix, x - 1, y, matrix[x][y], dp[x][y], dp);
        // rec(matrix, x, y + 1, matrix[x][y], dp[x][y], dp);
        // rec(matrix, x, y - 1, matrix[x][y], dp[x][y], dp);
        int count = 1;
        if (x > 0 && matrix[x - 1][y] > matrix[x][y]) {
            count = max(count, rec(matrix, x - 1, y, dp) + 1);
        }
        if (x < matrix.size() - 1 && matrix[x + 1][y] > matrix[x][y]) {
            count = max(count, rec(matrix, x + 1, y, dp) + 1);
        }
        if (y > 0 && matrix[x][y - 1] > matrix[x][y]) {
            count = max(count, rec(matrix, x, y - 1, dp) + 1);
        }
        if (y < matrix[0].size() - 1 && matrix[x][y + 1] > matrix[x][y]) {
            count = max(count, rec(matrix, x, y + 1, dp) + 1);
        }

        return dp[x][y] = count;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, -1));
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                rec(matrix, i, j, dp);
            }
        }

        int ans = 0;
        for (auto x : dp) {
            for (auto y : x) {
                ans = max(ans, y);
            }
        }
        return ans;
    }
};
