class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        for (int h : hand) {
            mp[h]++;
        }

        for (auto [x, y] : mp) {
            pq.push(x);
        }

        int current_group = 0;
        int last = -1;
        vector<int> v;
        while (!pq.empty()) {
            int top = pq.top();
            if (mp[top] > 1) v.push_back(top);
            pq.pop();
            if (last != -1 && top - last != 1) {
                return false;
            }

            current_group++;
            last = top;
            mp[top]--;
            if (current_group == groupSize) {
                last = -1;
                current_group = 0;
                for (auto x : v) {
                    pq.push(x);
                }
                v.clear();
            }
        }
        return current_group == 0;
    }
};
