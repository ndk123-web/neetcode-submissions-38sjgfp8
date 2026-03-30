class Solution {
public:
    string reorganizeString(string s) {
        // axyy   
        // y:2 a:1 , x:1, 
        // yaxy
        // q-> (y,0+1) next position 

        // ccccd
        // d:1 , c:4 
        int n = s.size();
        unordered_map<char,int> freq;
        string res = "";
        for (auto& c: s) {
            freq[c]++;
            if (freq[c] > (n + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<int,char>> mxheap;
        pair<int,char> block = {-1, '#'};

        for (auto& m :freq) {
            mxheap.push({m.second,m.first});
        }

        while (!mxheap.empty()) {
            pair<int,char> p = mxheap.top();
            mxheap.pop();
            
            res += p.second;
            p.first--;

            if (block.first > 0) {
                mxheap.push(block);
            }
            
            block = p;
        }

        return res.size() == n ? res : "";
    }
};