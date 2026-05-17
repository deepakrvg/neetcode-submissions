class Solution {
public:
    void rec(vector<vector<int>>& result, vector<int>& nums, int i, vector<int>& ans) {
        if (i >= nums.size()) {
            result.push_back(ans);
            return;
        }

        rec(result, nums, i + 1, ans);
        ans.push_back(nums[i]);
        rec(result, nums, i + 1, ans);
        ans.pop_back();
    }    

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        rec(result, nums, 0, ans);

        // vector<vector<int>> result;
        // for (auto v : st) {
        //     result.push_back(v);
        // }
        return result;
    }
};
