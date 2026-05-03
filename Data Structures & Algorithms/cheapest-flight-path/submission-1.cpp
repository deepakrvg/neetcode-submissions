class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (int j = 0; j < flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int wt = flights[j][2];
                if (dist[u] != INT_MAX) {
                    if (dist[u] + wt < temp[v]) {
                        temp[v] = dist[u] + wt;
                    }
                }
            }
            dist = temp;
        }
        if (dist[dest] == INT_MAX) return -1;
        return dist[dest];
    }
};
