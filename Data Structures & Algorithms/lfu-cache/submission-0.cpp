class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int,int>> valFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!valFreq.count(key)) return -1;

        int freq = valFreq[key].second;
        freqList[freq].erase(pos[key]);

        if (freqList[freq].empty() && freq == minFreq)
            minFreq++;

        freq++;
        freqList[freq].push_back(key);
        pos[key] = --freqList[freq].end();
        valFreq[key].second = freq;

        return valFreq[key].first;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (valFreq.count(key)) {
            valFreq[key].first = value;
            get(key); // reuse logic
            return;
        }

        if (valFreq.size() == cap) {
            int lfuKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            valFreq.erase(lfuKey);
            pos.erase(lfuKey);
        }

        valFreq[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};
