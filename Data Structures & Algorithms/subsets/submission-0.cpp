class Solution {
public:
    void rec(set<vector<int>>& st, vector<int>& nums, int i, vector<int>& ans) {
        if (i >= nums.size()) {
            st.insert(ans);
            return;
        }

        rec(st, nums, i + 1, ans);
        ans.push_back(nums[i]);
        rec(st, nums, i + 1, ans);
        ans.pop_back();
    }    

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ans;
        rec(st, nums, 0, ans);

        vector<vector<int>> result;
        for (auto v : st) {
            result.push_back(v);
        }
        return result;
    }
};
