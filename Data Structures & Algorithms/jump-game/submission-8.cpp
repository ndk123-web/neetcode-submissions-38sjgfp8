class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = 0;
        int n = nums.size();

        if (n == 1) return true;
        if (nums[0] == 0) return false;

        for (int i = 0 ; i < n - 1; i++) {
            if (i > maxR) {
                return false;
            }
            
            if (i + nums[i] >= n - 1) {
                return true;
            }

            maxR = max(maxR, i + nums[i]);
        }      

        return false;
    }
};
