class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        for (char ch : s) {
            if (ch == '(') {
                min_open++;
                max_open++;
            }
            else if (ch == ')') {
                min_open--;
                max_open--;
            }
            else {
                min_open--;
                max_open++;
            }
            if (min_open < 0) {
                min_open = 0;
            }
            if (max_open < 0) {
                return false;
            }
        }
        return min_open == 0;
    }
};
