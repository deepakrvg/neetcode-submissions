class Solution {
public:
    void rec(vector<int>& nums, int target, int i, int sum, vector<int>& ans, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(ans);
            return;
        }
        if (i >= nums.size() || sum > target) {
            return;
        }

        // take
        ans.push_back(nums[i]);
        rec(nums, target, i + 1, sum + nums[i], ans, result);
        ans.pop_back();

        // not take
        while (i < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        rec(nums, target, i + 1, sum, ans, result);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> result;
        rec(candidates, target, 0, 0, ans, result);
        return result;
    }
};
