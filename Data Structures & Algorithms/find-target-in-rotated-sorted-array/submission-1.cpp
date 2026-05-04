class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]) {
                if (target <= nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if (target >= nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                    ans = mid;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        if (ans == -1 || nums[ans] != target) {
            return -1;
        }
        return ans;
    }
};
