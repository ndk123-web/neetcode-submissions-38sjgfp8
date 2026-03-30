class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        vector<int> boundaries(4,0);

        // find left sorted and right sorted 
        while (l < r){
            int m = l + (r-l)/2;

            if (nums[m] > nums[r]) {
                l = m + 1;
            }else {
                r = m;
            }
        }   

        // when l == r it means 
        // 0 to l - 1 sorted 
        // l to n sorted 

        boundaries[0] = 0;
        boundaries[1] = l == 0 ? 0 : l - 1;
        boundaries[2] = l;
        boundaries[3] = nums.size()-1;

        int ll = boundaries[0];
        int lr = boundaries[1];
        while (ll <= lr) {
            int lm = ll + (lr-ll)/2;

            if (nums[lm] > target) {
                lr = lm - 1;
            }
            else if (nums[lm] < target) {
                ll = lm + 1;
            }
            else {
                return lm;
            }
        }

        int rl = boundaries[2];
        int rr = boundaries[3];
        while (rl <= rr) {
            int rm = rl + (rr-rl)/2;

            if (nums[rm] > target) {
                rr = rm - 1;
            }
            else if (nums[rm] < target) {
                rl = rm + 1;
            }
            else {
                return rm;
            }
        }


        return -1;
    }
};
