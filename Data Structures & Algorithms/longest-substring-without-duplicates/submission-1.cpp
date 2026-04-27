class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        unordered_set<char> st;
        for (int r = 0; r < n; r++) {
            // remove from left
            while (l <= r && st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }

            // insert from right
            if (st.find(s[r]) == st.end()) st.insert(s[r]);
            
            int len = st.size();
            ans = max(ans, len);
        }
        return ans;
    }
};
