class MyHashSet {
public:
    vector<int> customHashSet;
    
    MyHashSet() {    
    }
    
    void add(int key) {
        bool isDuplicateKey = false;
        for (int i = 0 ; i < this->customHashSet.size(); i++) {
            if (this->customHashSet[i] == key) {
                isDuplicateKey = true;
                break;
            }
        }
        if (!isDuplicateKey) {
            this->customHashSet.push_back(key);
        }

        return;
    }
    
    void remove(int key) {
        int k = 0;
        for (int i = 0 ; i < this->customHashSet.size(); i++) {
            if (this->customHashSet[i] != key) {
                this->customHashSet[k++] = this->customHashSet[i]; 
            }
        }

        this->customHashSet.resize(k);

        return;
    }
    
    bool contains(int key) {
        for (int i = 0 ; i < this->customHashSet.size(); i++) {
            if (this->customHashSet[i] == key) {
                return true; 
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */