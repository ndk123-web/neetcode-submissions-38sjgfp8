class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int mn = 0;
        int maxR = 0;

        while (curr < n - 1){

            int st = curr + 1;
            int end = curr + nums[curr];
            
            if (end >= n - 1) {
                return mn + 1;
            }

            bool foundMax = false;
            for (int i = st; i <= end && i < n; i++) {
                if (i + nums[i] > maxR) {
                    foundMax = true;
                    curr = i;
                    maxR = nums[i] + i;
                }
            }

            if (!foundMax) {
                curr = curr + nums[curr];
            }

            mn++;
        }

        return mn;        
    }
};
