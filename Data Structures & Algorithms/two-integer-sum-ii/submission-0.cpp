class Solution {
public:
    vector<int> twoSum(vector<int>& s, int target) {
        int n = s.size();
        int l = 0, r = n - 1;
        vector<int> ans(2);
        while (l <= r) {
            if (s[l] + s[r] == target) {
                ans[0] = l + 1;
                ans[1] = r + 1;
                return ans;
            }
            else if (s[l] + s[r] < target) {
                l++;
            }
            else r--;
        }
        return ans;
    }
};
