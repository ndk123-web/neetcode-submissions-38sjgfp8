class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currentSubarrayMxSum= 0, currentSubarrayMnSum = 0;      
        int maxSubarraySum = INT_MIN, minSubarrySum = INT_MAX;
        int totalSum = 0;

        for (int& num : nums) {

            // it tracks the normal kadane algorithm
            currentSubarrayMxSum = max(num, currentSubarrayMxSum + num);
            maxSubarraySum = max(maxSubarraySum, currentSubarrayMxSum);

            // it tracks the subarray which has minimum sum
            currentSubarrayMnSum = min(num, currentSubarrayMnSum + num);
            minSubarrySum = min(currentSubarrayMnSum, minSubarrySum);

            // it is total sum 
            totalSum += num;
        }

        if (maxSubarraySum < 0) {
            return maxSubarraySum;
        }

        // either normal max subarray sum 
        // or the totalSum - minSubarraySum (that includes the cycle loop)
        return max(maxSubarraySum, totalSum - minSubarrySum);
    }
};