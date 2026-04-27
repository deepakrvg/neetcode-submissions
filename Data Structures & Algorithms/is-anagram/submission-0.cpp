class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int i = 0, j = 0;
        bool ans = true;

        int n = s.size();
        int m = t.size();

        if (n != m) return false;

        while (i < n && j < m) {
            if (s[i] != t[j]) {
                ans = false;
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
};
