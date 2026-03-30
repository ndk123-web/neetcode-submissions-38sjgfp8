class Solution {
private:
    bool binary_search(vector<int>& nums, int target, int l , int r) {
        
        while (l <= r) {

            int m = l + (r-l)/2;

            if (nums[m] > target) {
                r = m - 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            while (l < n - 1 && nums[l] == nums[l+1] && nums[l] != target) l++;
            while (r > 0 && nums[r] == nums[r - 1] && nums[r] != target) r--;

            int m = l + (r-l)/2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            }else {
                r = m;
            }
        }

        int left_bound = l == 0 ? 0 : l - 1;
        bool isExist = binary_search(nums,target,0,left_bound);

        if (isExist) return isExist;

        return binary_search(nums,target,l,n-1);
    }
};