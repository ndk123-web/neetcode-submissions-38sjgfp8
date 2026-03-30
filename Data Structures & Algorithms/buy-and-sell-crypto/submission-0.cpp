class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int n = prices.size();

        int minDay = INT_MAX;

        for (int i = 0 ; i < n; i++) {
            minDay = min(minDay,prices[i]);
            maxProfit = max(maxProfit,prices[i]-minDay);
        }   

        return maxProfit;
    }
};
