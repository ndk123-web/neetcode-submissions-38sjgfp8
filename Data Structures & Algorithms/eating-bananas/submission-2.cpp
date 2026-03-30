class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int res = 1;

        while (left <= right) {
            int k = left + (right - left) / 2;

            long long th = 0;
            for (auto& pile : piles) {
                th = th + (pile + k - 1) / k;
            }
            if (th <= h) {
                right = k - 1;
                res = k;
            }else {
                left = k + 1;
            }
        }   

        return res;
    }
};
