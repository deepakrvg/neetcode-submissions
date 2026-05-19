class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            last_index[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int end = -1;
        int l = -1;
        for (int i = 0; i < n; i++) {
            end = max(end, last_index[s[i] - 'a']);
            if (end == i) {
                ans.push_back(i - l);
                l = i;
            }
        }
        return ans;
    }
};
