class Solution {
public:
    int rec(string& w1, string& w2, int i, int j, vector<vector<int>>& dp) {
        if (j == w2.size()) {
            return w1.size() - i;
        }
        if (i == w1.size()) {
            // insert operation
            return w2.size() - j;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int count = INT_MAX;
        if (w1[i] == w2[j]) {
            // char matches, do nothing
            count = min(count, rec(w1, w2, i + 1, j + 1, dp));
        }
        else {
            // insert operation
            count = min(count, rec(w1, w2, i, j + 1, dp) + 1);
            // delete operation
            count = min(count, rec(w1, w2, i + 1, j, dp) + 1);
            // replace operation
            count = min(count, rec(w1, w2, i + 1, j + 1, dp) + 1);
        }
        return dp[i][j] = count;
    }

    int minDistance(string word1, string word2) {
        int ans = 0;
        // vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // ans = rec(word1, word2, 0, 0, dp);
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));
        vector<int> prev(m + 1, INT_MAX - 1);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
            prev[j] = j;
        }
        
        for (int i = 1; i <= n; i++) {
            vector<int> curr(m + 1, INT_MAX - 1);
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = min(curr[j], prev[j - 1]);
                }
                else {
                    curr[j] = min(curr[j], prev[j] + 1);
                    curr[j] = min(curr[j], curr[j - 1] + 1);
                    curr[j] = min(curr[j], prev[j - 1] + 1);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
