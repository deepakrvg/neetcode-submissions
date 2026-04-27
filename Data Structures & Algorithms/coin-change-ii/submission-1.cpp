class Solution {
public:
    int rec(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (n < 0) {
            return 0;
        }

        if (amount == 0) {
            return 1;
        }

        if (dp[n][amount] != -1) {
            return dp[n][amount];
        }

        int count = 0;
        // take
        if (coins[n] <= amount) {
            count += rec(coins, amount - coins[n], n, dp);
        }
        // not take
        count += rec(coins, amount, n - 1, dp);
        return dp[n][amount] = count;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        ans = rec(coins, amount, n - 1, dp);
        return ans;
    }
};
