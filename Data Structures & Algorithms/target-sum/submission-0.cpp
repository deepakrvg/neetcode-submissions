class Solution {
public:
    vector<vector<int>> dp;
    int totalSum;

    int rec(vector<int>& nums, int target, int n, int sum) {
        // base condition
        if (sum == target && n < 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        if (dp[n][sum + totalSum] != -1) {
            return dp[n][sum + totalSum];
        }

        int count = 0;
        // add nums[n]
        count += rec(nums, target, n - 1, sum + nums[n]);
        // subtract nums[n]
        count += rec(nums, target, n - 1, sum - nums[n]);
        return dp[n][sum + totalSum] = count;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        totalSum = 0;
        for (int t : nums) totalSum += t;
        dp.resize(n, vector<int>(2 * totalSum + 1, -1));
        ans = rec(nums, target, n - 1, 0);
        return ans;
    }
};
