class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end());
        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {
            double time = (target - v[i].first) / (double) v[i].second;
            double last = time;
            if (!st.empty() && time <= st.top()) {
                last = st.top();
                st.pop();
            }
            st.push(last);
        }
        return st.size();
    }
};
