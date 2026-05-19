class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % (n + 1) != n) nums[nums[i] % (n + 1)] = nums[nums[i] % (n + 1)] + n + 1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                return i;
            }
        }
        return n;
    }
};
