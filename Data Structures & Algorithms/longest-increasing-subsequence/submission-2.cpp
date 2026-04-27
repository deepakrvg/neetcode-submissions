class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < i; k++) {
                if (nums[i] > nums[k]) {
                    dp[i] = max(dp[i], dp[k] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
