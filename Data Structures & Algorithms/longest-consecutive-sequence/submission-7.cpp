class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) return 0;

        // now it has all unique elements 
        unordered_set<int> sett(nums.begin(),nums.end());
        int res = 1;

        for (auto num : nums) {
            if (sett.find(num - 1) == sett.end()) {
                int len = 1;
                while (sett.find(num+len) != sett.end()) {
                    len++;
                }
                res = max(res,len);
            }
        }

        return res;
    }
};
