class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
    }
    
    void push(int val) {
        int mn;
        if (st.empty()) {
            mn = val;
        }
        else {
            mn = min(st.top().second, val);
        }
        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if (!st.empty()) return st.top().first;
    }
    
    int getMin() {
        if (!st.empty()) return st.top().second;
    }
};
