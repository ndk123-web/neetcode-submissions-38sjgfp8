class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int partProfit = 0;
        int maxProfit = 0;

        for (int i = 0 ; i < prices.size() - 1; i++) {
            if (prices[i] <= prices[i+1]) {
                partProfit = prices[i+1] - prices[i];
                maxProfit = maxProfit + partProfit;
                partProfit = 0;
            }
        }

        return maxProfit;
    }
};