class Solution {
public:
    int rec(string& s, int i, vector<int>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        
        if (dp[i] != -1) return dp[i];

        int count = rec(s, i + 1, dp);
        if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            count += rec(s, i + 2, dp);
        }
        return dp[i] = count;
    }

    int numDecodings(string s) {
        int count = 0;
        vector<int> dp(s.size(), -1);
        count = rec(s, 0, dp);
        return count;
    }
};
