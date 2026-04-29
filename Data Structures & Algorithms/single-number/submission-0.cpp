class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for (int& num : nums)
            mapp[num]++;
        
        for (auto& p : mapp) {
            if (p.second == 1) 
                return p.first;
        }

        return -1;
    }
};
