class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        heights.push_back(-1);
        stack<int> st;
        int area = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int cur = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                area = max(area, (i - l - 1) * heights[cur]);
            }
            st.push(i);
        }
        return area;
    }
};
