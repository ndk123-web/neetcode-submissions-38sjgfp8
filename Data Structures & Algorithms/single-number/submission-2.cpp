class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        // 5 6 5 
        // -> 5 ^ 6 = 1
        for (int& num : nums) {
            res = res ^ num;
        }

        return res;
    }
};
