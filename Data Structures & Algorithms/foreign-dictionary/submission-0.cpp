class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        int n = words.size();
        unordered_map<char, int> indegree;

        for (auto word : words) {
            for (auto ch : word) {
                indegree[ch] = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            string w1 = words[i - 1];
            string w2 = words[i];
            int j = 0, k = 0;
            while (j < w1.size() && k < w2.size() && w1[j] == w2[k]) {
                j++;
                k++;
            }
            if (j < w1.size() && k >= w2.size()) return "";
            if (j < w1.size() && k < w2.size()) {
                if (adj[w1[j]].find(w2[k]) == adj[w1[j]].end()) {
                    adj[w1[j]].insert(w2[k]);
                    indegree[w2[k]]++;
                }
            }
        }

        string ans = "";
        queue<char> q;
        for (auto [x, y] : indegree) {
            if (y == 0) {
                q.push(x);
                ans += x;
            }
        }

        while (!q.empty()) {
            char u = q.front();
            q.pop();
            for (auto x : adj[u]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                    ans += x;
                }
            }
        }

        if (ans.size() != indegree.size()) {
            return "";
        }

        return ans;
    }
};
