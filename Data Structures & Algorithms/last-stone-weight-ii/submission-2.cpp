class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = accumulate(stones.begin(),stones.end(),0);
        int target = stoneSum / 2;

        vector<int> dp(target + 1, false);
        
        // can build 0 with 0 
        dp[0] = true;      

        for (int i = 0; i < stones.size() ; i++) {

            for (int j = target; j >= stones[i]; j--) {
                if (j - stones[i] >= 0) {
                    dp[j] = dp[j] || dp[j-stones[i]];
                }
            }
        }

        for (int j = target; j >=0; j--) {
            if (dp[j]) {
                return stoneSum - 2*j;
            }
        }

        return 0;
    }
};