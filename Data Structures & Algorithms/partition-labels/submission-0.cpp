class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> total_freq;
        int n = s.size();
        for (char ch : s) {
            total_freq[ch]++;
        }

        int l = 0;
        unordered_map<char, int> current_window_freq;
        vector<int> ans;
        for (int r = 0; r < n; r++) {
            current_window_freq[s[r]]++;
            bool isMatch = true;
            for (auto [cx, cy] : current_window_freq) {
                if (total_freq[cx] != cy) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                current_window_freq.clear();
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return ans;
    }
};
