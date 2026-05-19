class Solution {
public:
    void rec(string digits, int i, vector<string>& mp, string s, vector<string>& ans) {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }
        
        for (char ch : mp[digits[i] - '0']) {
            rec(digits, i + 1, mp, s + ch, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string s;
        rec(digits, 0, mp, s, ans);
        return ans;
    }
};
