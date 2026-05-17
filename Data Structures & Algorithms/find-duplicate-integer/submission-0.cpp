class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // if (nums[i] / n >= 2) return i;
            nums[nums[i] % n] += n;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] / n >= 2) return i;
        }
        return -1;
    }
};
