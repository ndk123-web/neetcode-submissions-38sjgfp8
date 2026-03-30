class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // 1️⃣ Collect all unique characters
        for (string &word : words) {
            for (char c : word) {
                indegree[c] = 0;   // initialize all to 0
            }
        }

        // 2️⃣ Build graph from adjacent words
        for (int i = 1; i < words.size(); i++) {
            string &a = words[i - 1];
            string &b = words[i];

            int len = min(a.size(), b.size());
            int j = 0;

            while (j < len && a[j] == b[j]) {
                j++;
            }

            // ❗ Prefix invalid case
            if (j == len) {
                if (a.size() > b.size()) {
                    return "";
                }
                continue;
            }

            char from = a[j];
            char to   = b[j];

            // prevent duplicate edges
            bool exists = false;
            for (char nei : adj[from]) {
                if (nei == to) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                adj[from].push_back(to);
                indegree[to]++;
            }
        }

        // 3️⃣ Topological Sort (Kahn's Algorithm)
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        string result;

        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            result.push_back(curr);

            for (char nei : adj[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // 4️⃣ Cycle check
        if (result.size() != indegree.size()) {
            return "";
        }

        return result;
    }
};