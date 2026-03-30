class Solution {
private:    
    map<pair<int,bool>, int> mapp;

    int dfs(vector<int>& prices, int i, bool canBuyStock) {
        if (i >= prices.size()) {
            return 0;
        }

        if (mapp.find({i,canBuyStock}) != mapp.end()) {
            return mapp[{i,canBuyStock}];
        }

        if (canBuyStock) {
            return mapp[{i,canBuyStock}] = max(
                -prices[i] + dfs(prices, i+1, false),
                dfs(prices, i+1, true)
            );  
        } else {
            return mapp[{i,canBuyStock}] = max(
                prices[i] + dfs(prices, i+2, true),
                dfs(prices, i+1, false)
            );
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        return dfs(prices,0,true);        
    }
};
