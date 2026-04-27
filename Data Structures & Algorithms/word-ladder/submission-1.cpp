class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int dist = 1;
        bool flag = false;
        while (!q.empty()) {
            int len = q.size();
            dist++;
            for (int i = 0; i < len; i++) {
                string temp = q.front();
                q.pop();
                for (int i = 0; i < temp.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string s = temp;
                        s[i] = 'a' + j;
                        if (st.find(s) != st.end()) {
                            if (s == endWord) {
                                flag = true;
                                return dist;
                            }
                            q.push(s);
                            st.erase(s);
                        }
                    }
                }
            }
        }
        if (flag == false) return 0;
        return dist;
    }
};
