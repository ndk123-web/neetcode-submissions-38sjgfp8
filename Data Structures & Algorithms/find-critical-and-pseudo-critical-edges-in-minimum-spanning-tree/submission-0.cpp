class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

class Solution {
public:
    int buildMST(int n,
                 vector<vector<int>>& edges,
                 int skip,
                 int force) {

        DSU dsu(n);
        int weight = 0;
        int edgesUsed = 0;

        // 🔹 Force include edge first (if needed)
        if (force != -1) {
            auto &e = edges[force];
            if (dsu.unite(e[1], e[2])) {
                weight += e[0];
                edgesUsed++;
            }
        }

        // 🔹 Normal Kruskal
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip)
                continue;

            if (i == force)
                continue;

            auto &e = edges[i];

            if (dsu.unite(e[1], e[2])) {
                weight += e[0];
                edgesUsed++;
            }
        }

        // If not enough edges used → not a spanning tree
        if (edgesUsed != n - 1)
            return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges) {

        int m = edges.size();

        // 🔹 Add original index
        vector<vector<int>> newEdges;
        for (int i = 0; i < m; i++) {
            newEdges.push_back({edges[i][2], edges[i][0], edges[i][1], i});
        }

        // 🔹 Sort by weight
        sort(newEdges.begin(), newEdges.end());

        // 🔹 Compute base MST
        int baseWeight = buildMST(n, newEdges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        // 🔹 Test each edge
        for (int i = 0; i < m; i++) {

            // Test Critical
            if (buildMST(n, newEdges, i, -1) > baseWeight) {
                critical.push_back(newEdges[i][3]);
            }
            // Test Pseudo-Critical
            else if (buildMST(n, newEdges, -1, i) == baseWeight) {
                pseudo.push_back(newEdges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};