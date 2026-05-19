class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int best = INT_MIN;
        for (int num : nums) {
            sum = max(num, sum + num);
            best = max(best, sum);
        }
        return best;
    }
};
