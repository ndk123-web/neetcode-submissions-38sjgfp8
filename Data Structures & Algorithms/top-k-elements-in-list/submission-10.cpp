class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        vector<int> res;

        // why nums.size() + 1 ? because max freq will be nums.size() 
        vector<vector<int>> buckets(nums.size()+1) ;

        // count 
        for (auto& num : nums) {
            freqMap[num]++;
        }      

        // group the freq elemements
        for (auto& p : freqMap) {
            buckets[p.second].push_back(p.first);
        }

        // from last index get the k elemenets
        for (int i = buckets.size()-1; i > 0; i--) {
            for(int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};
