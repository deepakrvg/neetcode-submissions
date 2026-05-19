class Solution {
public:
    void rec(string& s, int left, vector<string>& ans, vector<vector<string>>& result) {
        if (left == s.size()) {
            result.push_back(ans);
            return;
        }

        for (int i = left; i < s.size(); i++) {
            int l = left;
            int r = i;
            bool isPalindrome = true;
            while (l <= r) {
                if (s[l] != s[r]) {
                    isPalindrome = false;
                    break;
                }
                l++;
                r--;
            }
            if (isPalindrome) {
                ans.push_back(s.substr(left, i - left + 1));
                rec(s, i + 1, ans, result);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> result;
        rec(s, 0, ans, result);
        return result;
    }
};
