class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                string temp = s.substr(i, j - i);
                if (dp[j] == true && st.find(temp) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
