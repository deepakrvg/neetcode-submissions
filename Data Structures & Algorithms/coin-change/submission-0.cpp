class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // state: dp[i] --> min coins required to get amount i
        // transition: dp[i] = min(dp[i], dp[i - coin] + 1), for all coins

        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // base case: for amount 0 we require 0 coins
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
