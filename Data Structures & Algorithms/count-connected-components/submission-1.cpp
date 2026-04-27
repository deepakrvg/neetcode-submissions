class DSU {
private:
    vector<int> rank;
    vector<int> parent;

public:
    int count;

    DSU(int n) {
        count = n;
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

    int unionByRank(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if (u_par == v_par) return count;
        count--;
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
        return count;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto edge : edges) {
            dsu.unionByRank(edge[0], edge[1]);
        }
        return dsu.count;
    }
};
