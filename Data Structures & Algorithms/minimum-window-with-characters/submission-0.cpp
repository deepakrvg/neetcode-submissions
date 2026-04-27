class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<int, int> f1, f2;
        for (auto x : t) {
            f1[x]++;
        }

        int l = 0;
        int have = 0;
        int need = f1.size();
        int ls = -1, rs = -1;
        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            f2[s[r]]++;
            if (f2[s[r]] == f1[s[r]]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    ls = l;
                    rs = r;
                }
                f2[s[l]]--;
                if (f2[s[l]] < f1[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (ls == -1 || rs == -1) return "";
        return s.substr(ls, rs - ls + 1);
    }
};
