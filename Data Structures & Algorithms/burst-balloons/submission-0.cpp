class Solution {
public:
    int rec(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        dp[l][r] = 0;
        for (int i = l; i <= r; i++) {
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += rec(nums, l, i - 1, dp) + rec(nums, i + 1, r, dp);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];
    }

    int maxCoins(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(1);
        for (int num : nums) {
            temp.push_back(num);
        }
        temp.push_back(1);

        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return rec(temp, 1, nums.size(), dp);
    }
};
