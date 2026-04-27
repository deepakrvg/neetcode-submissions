class DSU {
public:
    vector<int> rank;
    vector<int> parent;

    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    bool unionByRank(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if (u_par == v_par) return false;
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
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int len = edges.size();
        if (len != n - 1) return false;

        DSU dsu(n);

        for (auto edge : edges) {
            bool temp = dsu.unionByRank(edge[0], edge[1]);
            if (temp == false) return false;
        }

        return true;
    }
};
