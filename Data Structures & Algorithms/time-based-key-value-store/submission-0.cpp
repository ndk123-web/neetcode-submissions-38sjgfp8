class TimeMap {
    map<string,vector<pair<string,int>>> mapp;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mapp[key].push_back({value,timestamp});    
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> v = mapp[key];
        string res;

        for (auto& obj : v) {
            if (obj.second <= timestamp) {
                res = obj.first;
            }
        }

        return res;
    }
};
