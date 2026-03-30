class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sett(nums.begin(),nums.end());
        int res = 0;
        
        for (auto num : nums) {
            int curr = num;
            int streak = 0;

            while (sett.find(curr) != sett.end()) {
                curr++;
                streak++;
            }

            res = max(res,streak);
        }

        return res;
    }
};
