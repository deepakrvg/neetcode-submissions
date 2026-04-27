class DSU {
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU (int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    vector<int> unionByRank(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if (u_par == v_par) return {u, v};
        if (rank[u_par] > rank[v_par]) {
            parent[v_par] = u_par;
        }
        else if (rank[v_par] > rank[u_par]) {
            parent[u_par] = v_par;
        }
        else {
            parent[v_par] = u_par;
            rank[u_par]++;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DSU dsu(edges.size() + 1);
        for (vector<int> edge : edges) {
            ans = dsu.unionByRank(edge[0], edge[1]);
            if (ans.size() > 0) {
                return ans;
            }
        }
        return ans;
    }
};
