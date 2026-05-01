class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> result;
    int numTickets;

    bool dfs(string node) {
        if (result.size() == numTickets + 1) {
            return true;
        }

        if (adj.find(node) == adj.end()) {
            return false;
        }

        vector<string>& dest = adj[node];
        for (int i = 0; i < dest.size(); i++) {
            string u = dest[i];
            dest.erase(dest.begin() + i);
            result.push_back(u);

            if (dfs(u)) return true;

            dest.insert(dest.begin() + i, u);
            result.pop_back();
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        for (const auto& dest : tickets) {
            adj[dest[0]].push_back(dest[1]);
        }

        for (auto& [u, v] : adj) {
            sort(v.begin(), v.end());
        }

        result.push_back("JFK");
        dfs("JFK");
        return result;
    }
};
