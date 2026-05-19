class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        for (int h : hand) {
            mp[h]++;
        }
        for (auto [x, y] : mp) {
            pq.push(x);
        }

        while (!pq.empty()) {
            int top = pq.top();
            if (mp[top] == 0) {
                pq.pop();
                continue;
            }

            for (int i = 0; i < groupSize; i++) {
                int card = top + i;
                if (mp[card] == 0) {
                    return false;
                }
                mp[card]--;
            }
        }
        return true;
    }
};
