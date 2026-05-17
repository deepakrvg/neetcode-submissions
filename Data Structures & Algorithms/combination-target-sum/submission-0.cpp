class Solution {
public:
    void rec(vector<int>& nums, int target, int i, int sum, vector<int>& ans, set<vector<int>>& result) {
        if (sum == target) {
            result.insert(ans);
        }
        
        if (i == nums.size()) {
            return;
        }

        rec(nums, target, i + 1, sum, ans, result);
        if (sum + nums[i] <= target) {
            ans.push_back(nums[i]);
            rec(nums, target, i, sum + nums[i], ans, result);
            ans.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        set<vector<int>> result;
        rec(nums, target, 0, 0, ans, result);

        vector<vector<int>> a;
        for (auto v : result) {
            a.push_back(v);
        }
        return a;
    }
};
