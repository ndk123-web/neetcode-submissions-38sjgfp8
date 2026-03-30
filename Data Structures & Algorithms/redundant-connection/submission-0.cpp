class Solution {
private:    
    vector<int> parents;
    vector<int> res;

    int find(int node) {
        if (node == parents[node]) {
            return node;
        }

        return find(parents[node]);
    }

    bool unionEdge(int edge1, int edge2) {
        int parentOfEdge1 = find(edge1);
        int parentOfEdge2 = find(edge2);

        // if its a same then belongs to same group
        if (parentOfEdge1 == parentOfEdge2) {
            res.push_back(edge1);
            res.push_back(edge2);
            return true;
        }

        parents[parentOfEdge2] = parentOfEdge1;

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.assign(n+1,0);
        for (int i = 1 ; i <= n; i++) {
            parents[i] = i;
        }

        for (auto& edge : edges) {
            if (unionEdge(edge[0],edge[1])) {
                break;
            }
        }

        return res;
    }
};
