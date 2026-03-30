class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        int target = totalsum / 2;

        if (totalsum % 2 != 0) {
            return false;
        }

        vector<bool> dp(target+1, false);

        // initially it will be 0 -> true because to build 0 its true
        dp[0] = true;

        for (int num : nums) {

            for (int j = target ; j >= num; j--) {

                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];      
    }
};
