class Solution {
public:
    bool check(vector<int> &f1, vector<int>& f2) {
        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);

        int l = 0;
        int r = 0;
        int n = s1.size();
        int m = s2.size();
        while (r < n) {
            f1[s1[r] - 'a']++;
            f2[s2[r] - 'a']++;
            r++;
        }

        if (check(f1, f2)) return true;

        for (int i = r; i < m; i++) {
            f2[s2[i] - 'a']++;
            f2[s2[l] - 'a']--;
            if (check(f1, f2)) return true;
            l++;
        }

        return false;
    }
};
