class Solution {
public:
    // unordered_map<int, vector<pair<int, int>>> mp;
    
    int distance(vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>> pq;
        for (vector<int>& p : points) {
            int dist = distance(p);
            // mp[dist].push_back({p[0], p[1]});
            pq.push({dist, p[0], p[1]});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
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
