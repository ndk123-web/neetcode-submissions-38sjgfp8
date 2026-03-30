class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> v;
        vector<int> res;

        for (auto& num : arr) {
            v.push_back({abs(num-x),num});
        }

        sort(v.begin(),v.end(),[](auto &a, auto& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first; 
        });

        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }

        sort(res.begin(),res.end());
        return res;
    }   
};