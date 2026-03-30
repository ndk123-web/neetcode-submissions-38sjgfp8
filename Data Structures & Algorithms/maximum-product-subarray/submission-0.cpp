class Solution {
private:

    // int mn(int a, int b, int c) {
    //     int r = INT_MAX;

    //     if (a < b) {
    //         r = a;
    //     }

    //     return min(r,c);
    // }

    // int mx(int a, int b, int c) {
    //     int r = INT_MIN;

    //     if (a > b) {
    //         r = a;
    //     }

    //     return max(r,c);
    // }

public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int prevMn = res , prevMx = res;

        for (int i = 1; i < nums.size(); i++) {

            int oldMax = prevMx;
            int oldMin= prevMn;

            prevMx = max({nums[i], oldMin*nums[i], oldMax*nums[i]});
            prevMn = min({nums[i], oldMin*nums[i], oldMax*nums[i]});
            res = max({prevMx, prevMn, res});
        }   

        return res;
    }
};
