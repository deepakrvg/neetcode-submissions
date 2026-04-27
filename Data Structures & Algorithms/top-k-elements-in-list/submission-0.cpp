class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto [x, y] : mp) {
            pq.push({y, x});
        }

        vector<int> ans;
        while (k--) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back(y);
        }

        return ans;
    }
};
