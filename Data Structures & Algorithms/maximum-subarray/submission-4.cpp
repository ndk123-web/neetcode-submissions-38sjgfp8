class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, maxSum = 0;

        for (int& num : nums) {

            if (currentSum < 0) {
                currentSum = num;
                maxSum = max(maxSum,currentSum);
                continue;
            }

            currentSum += num;
            maxSum = max(maxSum, currentSum);
        }

        return currentSum < 0 ? -1 : maxSum;
    }
};
