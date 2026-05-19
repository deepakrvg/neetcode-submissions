class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int steps = 0;
        int prev_r = 0;
        for (int i = 0; i < n - 1; ++i) {
            r = max(r, nums[i] + i);
            if (r >= n - 1) {
                return steps + 1;
            }
            if (i == prev_r) {
                steps++;
                prev_r = r;
            }
        }
        return steps;
    }
};
