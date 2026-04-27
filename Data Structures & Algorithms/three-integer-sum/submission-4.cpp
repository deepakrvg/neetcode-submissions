class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int x = 0; x < n; x++) {
            if (x > 0 && nums[x] == nums[x - 1]) {
                continue;
            }
            int l = x + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == -nums[x]) {
                    ans.push_back({nums[l], nums[r], nums[x]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (nums[l] + nums[r] < -nums[x]) l++;
                else r--;
            }
        }
        return ans;
    }
};
