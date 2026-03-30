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

        if (v.empty()) {
            return res;
        }

        int l = 0;
        int r = v.size() - 1;

        while (l <= r) {
            int m = l + (r-l)/2;
            if (v[m].second < timestamp){
                res = v[m].first;
                l = m + 1;
            }
            else if (v[m].second > timestamp) {
                r = m - 1;
            }
            else {
                return v[m].first;
            }
        }

        return res;
    }
};
