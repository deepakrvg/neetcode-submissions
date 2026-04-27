class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        int maxFreq = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++) {
            // add element
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            // remove element
            while (l <= r && (r - l + 1 - maxFreq) > k) {
                mp[s[l]]--;
                l++;
            }

            // compute ans
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
