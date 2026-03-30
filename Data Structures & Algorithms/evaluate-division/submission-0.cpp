class Solution {
private:
    // a->b
    // b->c
    // ab->bc
    unordered_map<string, string> parents;
    
    // a->4
    // b->1
    // ab->3.25
    unordered_map<string, double> weight;

    string find(string x) {
        if (parents[x] != x) {
            string originalParent = parents[x];
            parents[x] = find(parents[x]);
            weight[x] = weight[x] * weight[originalParent]; 
        }
        return parents[x];
    }

    void unite(string a, string b, double value) {
        if (!parents.count(a)) {
            parents[a] = a;
            weight[a] = 1;
        }
        if (!parents.count(b)) {
            parents[b] = b;
            weight[b] = 1;
        }

        string rootA = find(a);
        string rootB = find(b);

        if (rootA != rootB) {
            parents[rootA] = rootB;
            weight[rootA] = value * (weight[b] / weight[a]);
        }

        return;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int t = 0;
        for (vector<string>& eq : equations) {
            unite(eq[0],eq[1],values[t++]);
        }

        vector<double> res;
        for(vector<string>& q : queries) {
            string a = q[0] , b = q[1];

            if (!parents.count(a) || !parents.count(b)) {
                res.push_back(-1.0);
            }
            else if (find(a) != find(b)) {
                res.push_back(-1.0);
            }
            else {
                res.push_back(weight[a] / weight[b]);
            }
        }

        return res; 
    }
};