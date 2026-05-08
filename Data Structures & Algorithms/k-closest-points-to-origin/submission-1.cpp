class Solution {
public:
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // unordered_map<int, vector<pair<int, int>>> mp;
    
    int distance(vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (auto p : points) {
            int dist = distance(p);
            // mp[dist].push_back({p[0], p[1]});
            pq.push({dist, p[0], p[1]});
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            auto [d, x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }

        // for (auto [u, v] : mp) {
        //     cout << u << " --> ";
        //     for (auto [x, y] : v) {
        //         cout << x << " " << y << endl;
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};
