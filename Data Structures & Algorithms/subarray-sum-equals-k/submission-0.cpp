class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0 ; i < n; i++) {
            int currSum = 0;  
            for (int j = i ; j < n ; j++) {
                currSum = currSum + nums[j];
                if (currSum == k) count++;
            }
        }

        return count;   
    }
};