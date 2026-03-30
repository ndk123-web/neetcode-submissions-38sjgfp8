class Solution {
private:
    vector<int> parent;

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return find(parent[node]);
    }

    bool unionSet(int n1, int n2) {
        int pn1 = find(n1);
        int pn2 = find(n2);

        if (pn1 == pn2) 
            return false;

        parent[pn2] = pn1;
        return true;   
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) 
            return false;

        parent.resize(n);

        // initially each node is leader of its own group 
        for (int i = 0 ; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            if (!unionSet(edge[0],edge[1]))
                return false;
        }

        return true;
    }
};
