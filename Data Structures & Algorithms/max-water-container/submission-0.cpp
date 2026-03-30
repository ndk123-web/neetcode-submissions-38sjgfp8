class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int maxAmount = INT_MIN , currentAmount = INT_MIN;

        while (left < right) {
            currentAmount = min(nums[left] , nums[right]) * (right-left);
            maxAmount = max(maxAmount,currentAmount);
            
            if (nums[left] > nums[right]) {
                right--;
            }else {  
                left++;
            }
        }

        return maxAmount;
    }
};
