class LRUCache {
private:   
    int size;
    list<int> ls;
    unordered_map<int,pair<int,list<int>::iterator>> mapp;

public:
    LRUCache(int capacity) {
        this->size = capacity;    
    }
    
    int get(int key) {
        // not present
        if (mapp.find(key) == mapp.end()) return -1;

        // present
        ls.erase(mapp[key].second);
        ls.push_back(key);
        mapp[key].second = --ls.end();
        return mapp[key].first;
    }
    
    void put(int key, int value) {
        if (mapp.find(key) != mapp.end()) {
            ls.erase(mapp[key].second);
        }
        else if (mapp.size() == size) {
            int lru = ls.front(); 
            ls.pop_front();
            mapp.erase(lru); // lru here is key 
        }
        ls.push_back(key);
        mapp[key] = {value,--ls.end()};
    }
};
