class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int,char>> pq;
        for (auto &p : freq)
            pq.push({p.second, p.first});

        string res = "";

        while (pq.size() >= 2) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            auto [cnt2, ch2] = pq.top(); pq.pop();

            res.push_back(ch1);
            res.push_back(ch2);

            if (--cnt1 > 0) pq.push({cnt1, ch1});
            if (--cnt2 > 0) pq.push({cnt2, ch2});
        }

        // One character may remain
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";
            res.push_back(pq.top().second);
        }

        return res;
    }
};
