class Solution {
public:
    int rec(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.size()) {
            return 1;
        }

        if (i == s.size() || j == t.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int count = 0;
        if (s[i] == t[j]) {
            count += rec(s, t, i + 1, j + 1, dp);
        }
        count += rec(s, t, i + 1, j, dp);
        return dp[i][j] = count;
    }

    int numDistinct(string s, string t) {
        int ans = 0;
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        ans = rec(s, t, 0, 0, dp);
        return ans;
    }
};
