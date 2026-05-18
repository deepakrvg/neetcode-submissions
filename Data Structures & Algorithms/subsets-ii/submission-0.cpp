class Solution {
public:
    void rec(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(ans);
            return;
        }
        if (i > nums.size()) {
            return;
        }

        ans.push_back(nums[i]);
        rec(nums, i + 1, ans, result);
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        ans.pop_back();
        rec(nums, i + 1, ans, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> result;
        rec(nums, 0, ans, result);
        return result;
    }
};
