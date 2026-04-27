class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n, 1);

        // for (int i = 0; i < m; i++) {
        //     dp[i][0] = 1;
        // }

        // for (int i = 0; i < n; i++) {
        //     dp[0][i] = 1;
        // }

        for (int i = 1; i < m; i++) {
            vector<int> curr(n, 0);
            curr[0] = 1;
            for (int j = 1; j < n; j++) {
                curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
