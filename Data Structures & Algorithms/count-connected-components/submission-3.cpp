class Solution {
private:
    vector<int> parents;
    int res;

    int find(int edge) {
        if (parents[edge] == edge) {
            return edge;
        }
        return find(parents[edge]);
    }

    void unionEdge(int e1, int e2) {
        int pe1 = find(e1);
        int pe2 = find(e2);
        
        if (pe1 != pe2) {
            parents[pe2] = pe1;
            // res--;
        }

        return;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Disjoint Union Set
        parents.assign(n,0);
        res = 1;

        for (int i = 0 ; i < n; i++) {
            parents[i] = i;
        } 

        for (auto& edge : edges) {
            unionEdge(edge[0],edge[1]);
        }

        for (int i = 0; i < n; i++) {
            parents[i] = find(i);
        }

        sort(parents.begin(),parents.end());

        int prev = parents[0];
        for (int i = 1; i< n; i++) {
            if (parents[i] != prev) {
                prev = parents[i];
                res++;
            }
        }

        return res;
    }
};
