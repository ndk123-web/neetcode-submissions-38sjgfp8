class LRUCache {
private:
    int size;
    vector<pair<int,int>> v;

public:
    LRUCache(int capacity) {
        this->size = capacity;    
    }
    
    int get(int key) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first == key) {
                pair<int, int> tmp = v[i];
                v.erase(v.begin() + i);
                v.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0 ; i < v.size(); i++) {
            if (v[i].first == key) {
                v.erase(v.begin() + i);
                v.push_back({key,value});
                return;
            }
        }

        if (v.size() == size) {
            v.erase(v.begin());
        }

        v.push_back({key,value});
        return;
    }
};
