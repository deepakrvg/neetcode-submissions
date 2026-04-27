class Solution {
public:
    int solve(vector<int>& nums, int st, int end) {
        int n = nums.size();
        // vector<int> dp(n + 2, 0);
        int prev1 = 0;
        int prev2 = 0;
        for (int i = st; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
