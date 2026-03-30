class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minVal = INT_MAX;
        int left = 0;
        int sum = 0;
        int n = nums.size();

        for (int right = 0 ; right < n; right++) {
            sum = sum + nums[right];

            while (sum >= target) {
                minVal = min(minVal,(right-left+1));
                sum = sum - nums[left];
                left++;
            }
        }

        return minVal == INT_MAX ? 0 : minVal;
    }
};