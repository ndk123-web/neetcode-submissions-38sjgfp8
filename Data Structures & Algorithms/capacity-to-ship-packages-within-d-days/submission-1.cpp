class Solution {
private:
    bool canShip(int minCap , vector<int>& weights, int days) {
        int ships = 1;
        int cap = minCap;

        for (auto& w : weights) {
            if (cap - w < 0) {
                ships++;
                cap = minCap;
            }
            cap = cap - w;
        }

        return ships <= days ? true : false;
    }
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        int res = left;

        while (left <= right) {
            int minCap = left + (right-left)/2;
            if (canShip(minCap,nums,days)) {
                res = minCap;
                right = minCap - 1;
            }else {
                left = minCap + 1;
            }
        }   

        return res;   
    }
};