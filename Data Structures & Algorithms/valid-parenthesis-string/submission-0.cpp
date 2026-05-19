class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.push(i);
            }
            else if (s[i] == '*') {
                star.push(i);
            }
            else {
                if (!open.empty()) {
                    open.pop();
                }
                else if (!star.empty()) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }
        while (!open.empty() && !star.empty()) {
            int o = open.top();
            int st = star.top();
            open.pop();
            star.pop();
            if (o > st) {
                return false;
            }
        }
        return open.empty();
    }
};
