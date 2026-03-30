class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        unordered_map<int,int> mapp;

        for (int i = 0 ; i < n ; i++) {
            mapp[nums[i]]++;
        }

        for (auto &part : mapp) {
            if (part.second > n / 2) {
                mx = part.first;
            }
        }

        return mx;
    }
};