class Solution {
private:
    int binary_search(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int m = left + (right-left)/2;

            if (nums[m] > target) {
                right = m - 1;
            }
            else if (nums[m] < target) {
                left = m + 1;
            }
            else {
                return m;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

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

        int left_b = l == 0 ? 0 : l - 1;
        int res = binary_search(nums,target,0,left_b);
        if (res != -1) {
            return res;
        }
        
        return binary_search(nums,target,l,nums.size()-1);
    }
};
