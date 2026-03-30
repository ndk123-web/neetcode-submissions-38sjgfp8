class Solution {
private:
        bool canSplit(vector<int>& nums, int largestAllowed, int k) {
        int subarray = 1, currSum = 0;
        for (auto& num : nums) {
            currSum = currSum + num;
            if (currSum > largestAllowed) {
                subarray++;
                if (subarray > k) return false;
                currSum = num;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int res = r;

        while (l <= r) {
            int m = l + (r-l)/2;

            if (canSplit(nums,m,k)) {
                res = m;
                r=m-1;
            }
            else {
                l=m+1;
            }
        }   
        return res;
    }
};