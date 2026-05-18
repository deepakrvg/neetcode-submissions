class Solution {
public:
    void rec(vector<int>& nums, int i, vector<int>& taken, vector<int>& ans, vector<vector<int>>& result) {
        if (ans.size() == nums.size()) {
            result.push_back(ans);
            return;
        }

        if (i >= nums.size()) {
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken[i] == 0) {
                ans.push_back(nums[i]);
                taken[i] = 1;
                rec(nums, i, taken, ans, result);
                ans.pop_back();
                taken[i] = 0;
                // rec(nums, i, taken, ans, result);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> taken(nums.size(), 0);
        vector<int> ans;
        vector<vector<int>> result;
        rec(nums, 0, taken, ans, result);
        return result;
    }
};
