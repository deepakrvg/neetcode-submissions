class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        for (auto [x, y] : mp) {
            if (pq.size() == k && pq.top().first < y) {
                pq.pop();
                pq.push({y, x});
            }
            else if (pq.size() < k) {
                pq.push({y, x});
            }
        }

        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back(y);
        }

        return ans;
    }
};
