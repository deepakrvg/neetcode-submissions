class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                if (!st.empty()) {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    int res;
                    if (t == "+") res = b + a;
                    if (t == "-") res = b - a;
                    if (t == "*") res = b * a;
                    if (t == "/") res = b / a;
                    st.push(res);
                }
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
