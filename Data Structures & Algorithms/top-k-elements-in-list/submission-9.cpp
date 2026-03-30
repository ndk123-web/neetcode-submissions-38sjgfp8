class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;

        for (auto& num : nums) {
            freqMap[num]++;
        }   

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;

        for (auto& p : freqMap) {
            heap.push({p.second,p.first});
            if (heap.size() > k) {
                heap.pop(); // assures most smallest freq element gets popped 
            }
        }

        vector<int> result;
        for (int i = 0 ; i < k ; i++) {
            result.push_back(heap.top().second);
            heap.pop();
        }

        return result;

    }
};
