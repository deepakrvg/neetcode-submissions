class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> res(temp.size());
        for (int i = temp.size() - 1; i >= 0; i--) {
            while (!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = 0;
            }
            else res[i] = st.top() - i;
            st.push(i);
        }
        return res;
    }
};
