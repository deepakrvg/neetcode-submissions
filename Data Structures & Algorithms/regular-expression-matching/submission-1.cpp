class Solution {
public:
    bool rec(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i >= s.size() && j >= p.size()) {
            return true;
        }
        if (j >= p.size()) {
            return false;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        bool ans = false;
        if (j < p.size() - 1 && p[j + 1] == '*') {
            ans = ans || rec(s, p, i, j + 2, dp);
            if (match) {
                ans = ans || rec(s, p, i + 1, j, dp);
            }
        }
        else {
            if (match) {
                ans = ans || rec(s, p, i + 1, j + 1, dp);
            }
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return rec(s, p, 0, 0, dp);
    }
};
