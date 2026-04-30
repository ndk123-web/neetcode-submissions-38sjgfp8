class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        /*
            Assume nums= [1,0,3]
            missing clearly is 2

            now if we do like this
            (1 ^ 0 ^ 3) ^ (0 ^ 1 ^ 2) ^ 3
            = 2 yo thats the xorr answer
        */
        int xorr = n;

        for (int i = 0; i < n; i++) {
            xorr = xorr ^ i ^ nums[i];
        }

        return xorr;
    }
};
