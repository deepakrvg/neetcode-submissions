class Solution {
public:
    void rec(vector<int>& nums, vector<int>& taken, vector<int>& ans, vector<vector<int>>& result) {
        if (ans.size() == nums.size()) {
            result.push_back(ans);
            return;
        }

        if (ans.size() > nums.size()) {
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken[i] == 0) {
                ans.push_back(nums[i]);
                taken[i] = 1;
                rec(nums, taken, ans, result);
                ans.pop_back();
                taken[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> taken(nums.size(), 0);
        vector<int> ans;
        vector<vector<int>> result;
        rec(nums, taken, ans, result);
        return result;
    }
};
