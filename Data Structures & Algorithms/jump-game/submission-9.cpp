class Solution {
public:

    // 0 1 2 3 
    // 1 0 1 0
    bool canJump(vector<int>& nums) {
        int maxR = 0;
        int n = nums.size();

        if (n == 1) return true;
        if (nums[0] == 0) return false;

        for (int i = 0 ; i < n - 1; i++) {
            if (maxR >= n-1) {
                return true;
            }
            
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
