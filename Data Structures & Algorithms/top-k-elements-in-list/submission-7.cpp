class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;

        for (auto& num : nums) {
            freqMap[num]++;
        }

        vector<pair<int,int>> arr;
        for (const auto& p : freqMap) {
            arr.push_back({p.second,p.first});
        }

        sort(arr.rbegin(),arr.rend());

        vector<int> result;
        for (int i = 0 ; i < k ; i++) {
            result.push_back(arr[i].second);
        }

        return result;

    }
};
