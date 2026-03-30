class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);

        // at most k + 1 times we need to iterate
        // logic -> iteration 1 => 1 edge (direct path)
        // logic -> iteration 2 => 2 edge (direct path by previous 1 edge path)
        // logic -> iteration i => i edge (direct path by previous (i-1) edge path) 
        
        prices[src] = 0;

        for (int i = 0 ; i <= k; i++) {
            vector<int> tempPrices = prices;

            for (vector<int>& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int c = flight[2];

                if (prices[s] == INT_MAX)   
                    continue;
                
                if (tempPrices[s] + c < tempPrices[d]) {
                    // prices[s] because of previous iteration edge cost
                    tempPrices[d] = prices[s] + c;
                }
            }

            prices = tempPrices;
        }   

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
