class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int steps = 0;
        int prev_r = 0;
        for (int i = 0; i < n; i++) {
            if (prev_r < i) {
                // cout << i << " ";
                steps++;
                prev_r = r;
            }
            r = max(r, i + nums[i]);
        }
        return steps;
    }
};
