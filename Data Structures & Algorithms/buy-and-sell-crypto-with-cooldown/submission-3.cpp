class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] + prices[1]);

        for (int i = 2; i < n; i++) {
            // buy
            dp[i][0] = max(dp[i - 2][1] - prices[i], dp[i - 1][0]);
            // sell
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }

        for (int i = 0; i <= n; i++) {
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }

        return dp[n - 1][1];
    }
};
