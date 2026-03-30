class MyHashMap {
public:

    vector<int> myHashMap;

    MyHashMap(): myHashMap(1000001,-1) {
    }
    
    void put(int key, int value) {
        myHashMap[key] = value;
    }
    
    int get(int key) {
        return myHashMap[key];
    }
    
    void remove(int key) {
        myHashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */