class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int kt, vector<int>& nums) {
        k = kt;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
