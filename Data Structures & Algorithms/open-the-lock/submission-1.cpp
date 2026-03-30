// at 0 0 0 0
// it calls (4*2) calls
// 1000, 0100, ... put these all in queue
// now aga

class Solution {
private:
    vector<string> childrens(string lock) {
        string next;
        vector<string> res;

        for (int i = 0 ; i < 4; i++) {
            next = lock;

            // end + '0' for again storing in char form in place
            next[i] = (next[i] - '0' + 1) % 10 + '0';
            res.push_back(next);

            next = lock;
            next[i] = (next[i] - '0' + 9) % 10 + '0';
            res.push_back(next);
        }

        return res;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> sett(deadends.begin(),deadends.end());
        queue<pair<string,int>> q;

        q.push({"0000",0});
        if (sett.count("0000")) return -1;
        sett.insert("0000");

        while (!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();

            for (string children : childrens(lock)) {
                // if (!sett.count(children)) {
                //     continue;
                // }
                if (target == children) return turns + 1;

                if (sett.find(children) == sett.end()) {
                    sett.insert(children);
                    q.push({children,turns+1});
                }

            }
        }
        return -1;
    }
};