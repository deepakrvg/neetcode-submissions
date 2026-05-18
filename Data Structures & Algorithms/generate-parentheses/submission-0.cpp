class Solution {
public:
    void rec(int n, int open, int close, string s, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if (close > open) {
            return;
        }

        if (close < open) {
            rec(n, open, close + 1, s + ')', ans);
        }
        if (open < n) rec(n, open + 1, close, s + '(', ans);
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        rec(n, 0, 0, s, ans);
        return ans;
    }
};
