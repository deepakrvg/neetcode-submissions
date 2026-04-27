class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                curr[j] = max(prev[j], curr[j - 1]);
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
